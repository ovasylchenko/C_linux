#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>

int get_int_number(int n, int m);  // n = 0: checks for Zero, m < 0: checks for less than Zero

void* plus_pid_id(void* thread_data); // функция увеличивающая переменную на 1

void my_stop(int sig, siginfo_t *si, void *unused); // мой обработчик сигнала CNTR+Z

int num_threads = 0; // сюда забираем количество пококов от родительчкого процесса
int thread_status = 0; // потоки будут выполняться пока эта переменная равна 0
int pid_id = 0; // эта переменная и будет увеличиваться на 1
int stop_tread = 0; // флаг который выставляет обработчик сигнала
pthread_mutex_t mutex; // мютекс 1
pthread_mutex_t mutex2; // мютекс 2


typedef struct{ // структура которая передает потоку информацию
	int thread_number; //номер потока
} pthrData;


int main(void){
	/*----устанвливаем обработчик сигнала-----*/
	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = NULL;
	sa.sa_sigaction = my_stop;
	if(sigaction(SIGTSTP, &sa, NULL) == -1){
		printf("erorr\n\r");
		return -1;
	}
	/*-------------------------------------------*/

	int i = 0; // счетчик в цикле
	pthread_mutex_init(&mutex, NULL); // инициализация мютексов
	pthread_mutex_init(&mutex2, NULL);
	printf("please input an integer number of threads from 1 to 9\n\r");
	num_threads = get_int_number(0,-1); // забрали количество потоков
	sleep (1); // задержка 1 сек для того что бы глаза успели увидеть
	printf("You chouse %d threads\n\r", num_threads);
	sleep(1); // задержка 1 сек для того что бы глаза успели увидеть

	/*--так как сколько потоков будет мы зарание не знаем пользуеммся малоком ---*/
	pthread_t* threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
	pthrData* threadData = (pthrData*) malloc(num_threads * sizeof(pthrData));
	/*-------------------------------------------*/
	/* запускаем потоки и заставляем процес ждать их окончания */

	for (i=0; i<num_threads;i++){
		threadData[i].thread_number = (i+1);
		pthread_create(&(threads[i]), NULL, plus_pid_id,  &threadData[i]);
	}
	// важно джойнить не в предыдущем цикле, ибо первый приджойнившийся не дасть продолжиться программе и другие потоки не запустяться
	for (i=0; i<num_threads;i++){
		pthread_join(threads[i], NULL);
	}
	free(threads); // освобождаем память
	free(threadData);
	return 0;
}

void my_stop(int sig, siginfo_t *si, void *unused){ // мой обработчик сигнала CNTR+Z
	stop_tread = 1; // выставили флаг
}

void* plus_pid_id(void* thread_data) {
	pthrData* data = (pthrData*)thread_data; // приняли информацию от родителя
	int a = 0;
	a = data->thread_number;

	while (!thread_status){ // условие задачи
		pthread_mutex_lock(&mutex2);
		if (stop_tread){ // если нажали CNTR+Z то ми завершаем один поток
			stop_tread = 0; // что бы не мешать другим потокам обнуляем флаг
			pthread_mutex_unlock(&mutex2);
			printf("thread number %d is cancelled!\n\r", a);
			break; // выходим из цикла
		}
		else{ // что бы мютекс точно освободился
			pthread_mutex_unlock(&mutex2);
		}
		pthread_mutex_lock(&mutex);
		if (pid_id >= 20){ // что бы вечно не считать дощитаем до 20
			thread_status = 1; // а это что бы другие потоки завершились, вполне можна обойтись без этой строчки;
		}
		else{
			pid_id++;
			printf("Hello from thread number %d!\n\r", a);
			printf("new pid  = %d\n\r", pid_id);
		}
		pthread_mutex_unlock(&mutex);
		sleep (1); // задержка 1 сек для того что бы глаза успели увидеть
	}
	return 0;
}

int get_int_number(int n, int m) {
/* program that return number from user, "n" and "m" used for checking special conditions*/

    int num_f;
    int c; // used to obtain char from buffer
    bool chek0 = true;  // when chek0 == false, signals that input data are correct
    int dummy_chek = 0;  // interrupts program after 5 incorrect inputs

    while (chek0) {
        if (scanf("%d",&num_f) !=1) {
            printf("please input an integer!!!\n\r");
            dummy_chek++;
            while(true) {    //cleans buffer, must be specified for different cases
                c=getchar();
                if (c == '\n' || c == '\r' || c == EOF)
                    break;
            }
        }
        else {
            c=getchar();
            if (c == '\n' || c == '\r' || c == EOF) {
                chek0 = false;
                if (n == 0) {  // checking for non Zero value
                    if (num_f == 0) {
                        dummy_chek++;
                        printf("this integer cannot be Zero, please input other number!\n\r");
                        chek0 = true;
                    }
                }
                if (m < 0) {  // checking for less than Zero value
                    if (num_f < 0) {
                        dummy_chek++;
                        printf("this integer cannot be less Zero, please input other number!\n\r");
                        chek0 = true;
                    }
                }
                if (num_f > 9){
                	dummy_chek++;
					printf("this integer cannot be more than 9, please input other number!\n\r");
					chek0 = true;
                }
            }
            else {
                printf( "please input an integer!!!\n\r");
                dummy_chek++;
                while(true) {    //cleans buffer, must be specified for different cases
                    c=getchar();
                    if (c == '\n' || c == '\r' || c == EOF)
                        break;
                }
            }
        }
        if (dummy_chek == 5) {
            printf( "i dont have time for this, bye!\n\r");
            exit(EXIT_FAILURE);
        }
    }
    return num_f;
}
