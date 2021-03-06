#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double get_number(int n, int m);  // n = 0: checks for Zero, m < 0: checks for less than Zero

int main(void) {
    double num1, num2;

    printf( "Input the first number:\n\r");  //ask first number from user
    num1 = get_number(1, 1);

    printf( "Input the second number:\n\r");  //ask second number from user
    num2 = get_number(0, 1);

    printf("sum = %20.15g\n\r", (num1 + num2));  // sum
	printf("difference = %27.15g\n\r", (num1 - num2)); //difference
	printf("product = %24.15g\n\r", (num1 * num2)); //product
	printf("quotient = %25.15g\n\r", (num1 / num2)); //quotient
	printf("remainder = %26.15g\n\r", fmod(num1, num2)); //remainder
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
