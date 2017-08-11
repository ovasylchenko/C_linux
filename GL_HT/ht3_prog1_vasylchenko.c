#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int get_number(int n, int m);  // n = 0: checks for Zero, m < 0: checks for less than Zero

int main(void) {
    int value, bit_p;
    int a;

    printf( "Input the value:\n\r");  //ask value from user
    value = get_number(1, 1);

    printf( "Input the bit position:\n\r");  //ask bit position from user
    bit_p = get_number(0, -1);

    a = value&(int)(pow(2,(bit_p-1))); // or use (1<< bit_p)
    if (a == 0)
        printf ("bit %d is set to: 0\n\r", bit_p);
    else
        printf ("bit %d is set to: 1\n\r", bit_p);
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
                printf("please input an integer!!!\n\r");
                dummy_chek++;
                while(true) {    //cleans buffer, must be specified for different cases
                    c=getchar();
                    if (c == '\n' || c == '\r' || c == EOF)
                        break;
                }
            }
        }
        if (dummy_chek == 5) {
            printf("i dont have time for this, bye!\n\r");
            exit (EXIT_FAILURE);
        }
    }
    return num_f;
}