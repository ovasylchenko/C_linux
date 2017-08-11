#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double get_number(int n, int m);  // n = 0: checks for Zero, m < 0: checks for less than Zero

int main(void) {
    double weight, height, bmi;
    char s1[] = "Obese";
    char s2[] = "Underweight";
    char s3[] = "Normal";
    char s4[] = "Overweight";

    printf( "Input your height in Inches:\n\r");
    weight = get_number(0, -1);

    printf( "Input your weight in Pounds:\n\r");
    height = get_number(0, -1);

    bmi = (703*weight)/(height*height);

    printf("BMI VALUES:\nUnderweight: less than 18.5\nNormal: between 18.5 and 24.9\n");
    printf("Overweight: between 25 and 29.9\nObese: 30 or greater\n");
    printf("------------------------------------\n");

    if (bmi < 18.5)
        printf("Yours: %.10g - %s\n", bmi, s2);
    if (bmi >= 18.5 && bmi <= 24.9)
        printf("Yours: %.10g - %s\n", bmi, s3);
    if (bmi > 24.9 && bmi < 30)
        printf("Yours: %.10g - %s\n", bmi, s4);
    if (bmi >= 30)
        printf("Yours: %.10g - %s\n", bmi, s1);
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
