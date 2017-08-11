#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int get_number(int n, int m);  // n = 0: checks for Zero, m < 0: checks for less than Zero

int main(void) {
    int howmany;
	int counter;
	int value;
	int smallest;

	printf("How many integers will you enter?:\n\r");
	howmany = get_number(0, -1);

	for(counter=0; counter < howmany; counter++){
		printf("Enter integer number %d:\n\r", (counter+1));
		value = get_number(1, 1);
		if (value<INT_MAX)
		    smallest=value;
		if(value<smallest)
			smallest=value;
	}
    printf("Smallest value is: %d\n\r", smallest);
    return 0;
}

int get_number(int n, int m) {
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
            exit (EXIT_FAILURE);
        }
    }
    return num_f;
}
