#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double get_number(int n, int m);  // n = 0: checks for Zero, m < 0: checks for less than Zero

int main(void)
{
    double miles, cost, mpg, parking, tolls, res;

    printf("Total miles driven per day?\n\r");
    miles = get_number(1, -1);

    printf("Cost per gallon of gasoline?\n\r");
    cost = get_number(1, -1);

    if (cost == 0) {
        printf("nice, you have an electrocar!\n\r\n\r");
        mpg = 1;
    }
    else {
        printf("Average miles per gallon?\n\r");
        mpg = get_number(0, -1);
    }
    printf("Parking fees per day?\n\r");
    parking = get_number(1, 1);
    if (parking < 0)
        printf("somebody pay you for parking on their territory?\n\r\n\r");

    printf("Tolls per day?\n\r");
    tolls = get_number(1, 1);
    if (parking < 0)
        printf("somebody pay you for driving?\n\r\n\r");

    res = (miles*cost/mpg) + parking + tolls;
    printf("your daily driving cost = %.15g\n\r", res);
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
