#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int get_int_number(int n, int m);  // n = 0: checks for Zero, m < 0: checks for less than Zero

char get_char_from_number(int z);

char num_threads[] = {'0'}; // тут будет храниться количетсво треадов в дочернем процессе и передаваться ему

int main(void){
	int threads_num = 0; // сюда запрашиваем у пользователя количество тредов
	int status; // необходим для waitpid
	pid_t new_proces0; // тут хранится индетификатор новоого процеса
	printf("please input an integer number of threads from 1 to 9\n\r");
	threads_num = get_int_number(0,-1); // забираем от юзера целое (можна было и больше 9 сделать, но для экономии времени сделал так)
	num_threads[0] = get_char_from_number(threads_num); // так как передавать агрументом в новый процес инт нельзя переводим в масив
	printf("Original program,  pid = %d\n\r", getpid()); // печатаем айди родительского процесса
	sleep (1); // задержка 1 сек для того что бы глаза успели увидеть
	switch(new_proces0 = fork()){ // делаем новый процесс
		case 0:{// если удачно то то печатаем его айди
			printf("In child process,  pid = %d\n\r", getpid());
			execl("./2.out", num_threads, NULL); // подменяем новым контекстом и передаем количесво треадов в ньом
			break;
		}
		case -1:{ // в случаи ошибки выходим из родителя
			printf("erorr to create fork process\n\r");
			exit(EXIT_FAILURE);
		}
		default:{
			waitpid(new_proces0, &status, 0); // ждем окончания дочернего процесса
			printf("In parent,  pid=%d,  fork returned=%d\n\r", getpid(), new_proces0);
			sleep (1); // задержка 1 сек для того что бы глаза успели увидеть
		}
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

char get_char_from_number(int z){ // решение похоже на костыль, но они пришло первым в голову и работает
	switch(z){
		case 1:{
			return '1';
		}
		case 2:{
			return '2';
		}
		case 3:{
			return '3';
		}
		case 4:{
			return '4';
		}
		case 5:{
			return '5';
		}
		case 6:{
			return '6';
		}
		case 7:{
			return '7';
		}
		case 8:{
			return '8';
		}
		case 9:{
			return '9';
		}
		default : return '0';
	}
}
