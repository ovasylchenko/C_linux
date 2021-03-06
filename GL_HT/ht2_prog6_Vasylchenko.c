#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

double get_number(int n, int m);  // n = 0: checks for Zero, m < 0: checks for less than Zero

int main(void) {
	double precision;
	int j;
	int i = 1;
	double f;
	double en = 1.0;
    double e = 0;

    printf("Input precision:\n\r");  //ask precision from user
    precision = get_number(0, -1);

	while (fabs(en - e) > precision) {
		e = en;
		for (j = 1, f = 1.0; j <= i; j++) // scores factorial of n
			f *= j;
		i++;
		en += 1.0 / f; // sum of the elements
	}	
	printf("The e value is %.25g\n\r", en);

    return 0;
}
double get_number(int n, int m) {
/* program that return number from user, "n" and "m" used for checking special conditions*/

    double num_f;
    int c; // used to obtain char from buffer
    bool chek0 = true;  // when chek0 == false, signals that input data are correct
    int dummy_chek = 0;  // interrupts program after 5 incorrect inputs

    while (chek0) {
        if (scanf("%lf",&num_f) !=1) {
            printf("please input a number!!!\n\r");
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
                        printf("this number cannot be Zero, please input other number!\n\r");
                        chek0 = true;
                    }
                }
                if (m < 0) {  // checking for less than Zero value
                    if (num_f < 0) {
                        dummy_chek++;
                        printf("this number cannot be less Zero, please input other number!\n\r");
                        chek0 = true;
                    }
                }
            }
            else {
                printf( "please input a number!!!\n\r");
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