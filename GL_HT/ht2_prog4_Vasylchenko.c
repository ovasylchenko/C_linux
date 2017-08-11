#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE_STR 1000  // max size of string
#define PAL_SIZE 5  // size of palindrome

int ask_yes_no(void);  // ask action move if input data are incorrect

int main(void) {
    char str_u[MAX_SIZE_STR] = "";
    int a;  // used with ask_yes_no
    int len_str;
    int h_len_str;  // half of str length
    int i = 0;
    int j = 0;

    printf("please input test %d digit number:\n\r", PAL_SIZE);
    fflush(stdin);
    fgets(str_u, MAX_SIZE_STR, stdin);
    len_str = strlen(str_u);
    if (str_u[(len_str-1)] == '\n' || str_u[(len_str-1)] == '\r')
        len_str--;  // fgets can add '\n' at the and of line so must consider if

    for (i = 0; i < len_str; i++) {  // checking for a number or string
        if ((a=isalpha(str_u[i])) != 0){
            printf("this is not a number! Perform as a string? y\\n?\n\r");
            if (a=ask_yes_no())
                break;
            else
                return -1;
        }
    }

    if (len_str != PAL_SIZE) {  // checking size of input data
        printf("this is not a %d element object! Perform anyway? y\\n?\n\r", PAL_SIZE);
        if (a=ask_yes_no())
            ;
        else
            return -1;
    }

    h_len_str = len_str / 2;
    for (j=0; j< h_len_str; j++){  // checking for a palindrome
        if (str_u[j] == str_u[len_str-1])
            ;
        else {
            printf("Not a palindrome!\n\r");
            return 0;
        }
        len_str--;
    }
    printf("Is a palindrome!\n\r");
    return 0;
}

int ask_yes_no(void) {
/* program that ask user for action move if input data are incorrect*/

    int dummy_chek = 0;  // interrupts program after 5 incorrect inputs
    bool chek_ask = true;
    int len_ask;
    char ask[8] ="";

    while (chek_ask) {
            fflush(stdin);
            fgets(ask, 8, stdin);
            len_ask = strlen(ask);
            if ((len_ask-1) == 1 && (ask[0]=='y' || ask[0]=='n')) {
                if (ask[0]=='y')
                    return 1;
                else
                    return 0;
                }
            else {
                dummy_chek++;
                printf("please input y or n\n\r");
            }
            if (dummy_chek == 5) {
                printf("i dont have time for this, bye!\n\r");
                exit(EXIT_FAILURE);
            }
        }
    return -1;
}
