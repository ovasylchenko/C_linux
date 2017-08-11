#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>

int char_to_number(char c);

void* plus_pid_id(void* thread_data); // функция увеличивающая переменную на 1

pthread_mutex_t mutex; // мютекс 1
int pid_id = 0; // эта переменная и будет увеличиваться на 1
int thread_status = 0; // потоки будут выполняться пока эта переменная равна 0

typedef struct{ // структура которая передает потоку информацию
	int thread_number; //номер потока
} pthrData;

int main(int argc, char **argv){
	int num_threads = 0; // сюда забираем количество пококов от родительчкого процесса
	int i = 0; // счетчик в цикле
	pthread_mutex_init(&mutex, NULL); // инициализация мютекса
	num_threads = char_to_number(*argv[0]); // забрали количество потоков
	sleep (1); // задержка 1 сек для того что бы глаза успели увидеть
	printf("You chouse %d threads\n\r", num_threads);
	sleep(1); // задержка 1 сек для того что бы глаза успели увидеть

	/*--так как сколько потоков будет мы незнаем пользуеммся малоком ---*/
	pthread_t* threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
	pthrData* threadData = (pthrData*) malloc(num_threads * sizeof(pthrData));
	/*-------------------------------------------*/
	/* запускаем потоки и заставляем процес ждать их окончания */

	for (i=0; i<num_threads;i++){
		threadData[i].thread_number = (i+1);
		pthread_create(&(threads[i]), NULL, plus_pid_id,  &threadData[i]);
	}
	for (i=0; i<num_threads;i++){
		pthread_join(threads[i], NULL);
	}
	free(threads); // освобождаем память
	free(threadData);
	return 0;
}

void* plus_pid_id(void* thread_data) {
	pthrData* data = (pthrData*)thread_data; // приняли информацию от родителя
	int a = 0;
	int local_var = 0;
	a = data->thread_number;
	while (!thread_status){ // условие задачи
		if (pid_id >= 20){ // что бы вечно не считать дощитаем до 20
			thread_status = 1; // а это что бы другие потоки завершились, можно обойтись на только ретурном, но так на пару тактов может будет быстрее;
			return 0;
		}
		else{
			pthread_mutex_lock(&mutex);
			pid_id++;
			local_var = pid_id;
			pthread_mutex_unlock(&mutex);
			printf("Hello from thread number %d!\n\r", a);
			printf("new pid  = %d\n\r", local_var);
		}
		sleep (1); // задержка 1 сек для того что бы глаза успели увидеть
	}
	return 0;
}

int char_to_number(char c){ // переводим полученное в масиве количество потоков в инт, да как то очень на костыль похоже
	switch(c){
		case '1':{
			return 1;
		}
		case '2':{
			return 2;
		}
		case '3':{
			return 3;
		}
		case '4':{
			return 4;
		}
		case '5':{
			return 5;
		}
		case '6':{
			return 6;
		}
		case '7':{
			return 7;
		}
		case '8':{
			return 8;
		}
		case '9':{
			return 9;
		}
		default : return 0;
	}
}
