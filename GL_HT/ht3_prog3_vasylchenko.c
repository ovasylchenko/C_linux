#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>




struct address ip_to_int (char *ip);  // convert string ip(na, nm) in to int array

int number_char(char s);  // convert char to int

int ipchecker(char* ip, char* na, char* nm);  // check if ip in network using network mask

int ask_yes_no(void);  // ask action move if input data are incorrect

struct address {
    int mas[4];
};



int main(void) {

    ipchecker("192.168.0.1", "192.168.1.1", "255.255.0.0");

    return 0;
}


int ipchecker(char* ip, char* na, char* nm){
/* use ip, network address (na), network mask (nm) and returns 1
if ip is part of network represented by na/nm and 0 (zero) otherwise*/

    struct address ip_m;
    struct address na_m;
    struct address nm_m;
    int i, j;  // counters
    int a;  // used with ask_yes_no

    ip_m = ip_to_int(ip);
    na_m = ip_to_int(na);
    nm_m = ip_to_int(nm);

    for (i=0; i<=3; i++) {  // checking for correct na address
        if (((nm_m.mas[i])^255)&(na_m.mas[i]) != 0) {  // if na correct (nm(xor)255)&na gives 0
            printf("%s is wrong network address! Perform anyway? y\\n?\n\r", na);
            if (a=ask_yes_no()) {
                for (j=0; j<=3; j++) {
                    na_m.mas[j] = (na_m.mas[j])&(nm_m.mas[j]);  // fixing na
                }
                break;
            }
            else
                return -1;
            }
    }

    for (i=0; i<=3; i++) {  // converting ip to na
        ip_m.mas[i] = (ip_m.mas[i])&(nm_m.mas[i]);
        if (ip_m.mas[i] != na_m.mas[i]) {
            printf("%s not in %s network!\n\r", ip, na);
            return 0;
        }
    }
    printf("%s in %s network\n\r", ip, na);
    return 1;
}
struct address ip_to_int (char *ip) {
/* convert string ip(na, nm) in to int array, terrible version,
 return struct address erorr = {-1,-1,-1,-1} if incorrect ip(na, nm)
 maybe can use for cucle for all 4- elements*/

    struct address add1;
    struct address erorr = {-1,-1,-1,-1};
    int temp = 0;  //use in cycle processing string ip
    int a;  // used with isalpha
    int i = 0,  j = 0;  // counters
    int ch1 = 0, ch2 = 0, ch3 = 0, ch4 = 0; // int with ip
    int len = 0;
    int sym = 0;

    for (i=temp, len=0; i<=(temp+3); i++) {  // cycle for first number in ip
        if (ip[i] == '\0')
            break;
        if (ip[i] == '-') {
            printf("%s incorrect data!\n\r", ip);
            return erorr;
        }
        if (ip[i] != '.') {  // stops if receives '.'
            if (a=isalpha(ip[i]) == 0) {  // if not correct ip exit with -1
                 len++;
                 sym++;
            }
            else {
                printf("%s incorrect data!\n\r", ip);
                return erorr;
            }
        }
        else
            break;
    }
    if (len > 3 || len < 1) {
        printf("%s incorrect data!\n\r", ip);
        return erorr;
    }
    if (len == 3) {
        if ((a = number_char(ip[0])) > 2) {
            printf("%s incorrect data!\n\r", ip);
            return erorr;
        }
        else {
            ch1 += 100*(number_char(ip[(sym-len)]));
            ch1 += 10*(number_char(ip[(sym-len+1)]));
            ch1 += 1*(number_char(ip[(sym-len+2)]));
        }
    }
    if (len == 2) {
        ch1 += 10*(number_char(ip[(sym-len)]));
        ch1 += 1*(number_char(ip[(sym-len+1)]));
    }
    if (len == 1) {
        ch1 += 1*(number_char(ip[(sym-len)]));
    }
    sym++;  // add fot '.' element
    temp = sym;  // start position for next cycle
    add1.mas[0] = ch1;  // not safe but works

    for (i=temp, len=0; i<=(temp+3); i++) {  // cycle for first number in ip
        if (ip[i] == '\0')
            break;
        if (ip[i] == '-') {
            printf("%s incorrect data!\n\r", ip);
            return erorr;
        }
        if (ip[i] != '.') {  // stops if receives '.'
            if (a=isalpha(ip[i]) == 0) {  // if not correct ip exit with -1
                 len++;
                 sym++;
            }
            else {
                printf("%s incorrect data!\n\r", ip);
                return erorr;
            }
        }
        else
            break;
    }
    if (len > 3 || len < 1) {
        printf("%s incorrect data!\n\r", ip);
        return erorr;
    }
    if (len == 3) {
        if ((a = number_char(ip[0])) > 2) {
            printf("%s incorrect data!\n\r", ip);
            return erorr;
        }
        else {
            ch2 += 100*(number_char(ip[(sym-len)]));
            ch2 += 10*(number_char(ip[(sym-len+1)]));
            ch2 += 1*(number_char(ip[(sym-len+2)]));
        }
    }
    if (len == 2) {
        ch2 += 10*(number_char(ip[(sym-len)]));
        ch2 += 1*(number_char(ip[(sym-len+1)]));
    }
    if (len == 1) {
        ch2 += 1*(number_char(ip[(sym-len)]));
    }
    sym++;  // add fot '.' element
    temp = sym; // start position for next cycle
    add1.mas[1] = ch2;
    for (i=temp, len=0; i<=(temp+3); i++) {  // cycle for first number in ip
        if (ip[i] == '\0')
            break;
        if (ip[i] == '-') {
            printf("%s incorrect data!\n\r", ip);
            return erorr;
        }
        if (ip[i] != '.') {  // stops if receives '.'
            if (a=isalpha(ip[i]) == 0) {  // if not correct ip exit with -1
                 len++;
                 sym++;
            }
            else {
                printf("%s incorrect data!\n\r", ip);
                return erorr;
            }
        }
        else
            break;
    }
    if (len > 3 || len < 1) {
        printf("%s incorrect data!\n\r", ip);
        return erorr;
    }
    if (len == 3) {
        if ((a = number_char(ip[0])) > 2) {
            printf("%s incorrect data!\n\r", ip);
            return erorr;
        }
        else {
            ch3 += 100*(number_char(ip[(sym-len)]));
            ch3 += 10*(number_char(ip[(sym-len+1)]));
            ch3 += 1*(number_char(ip[(sym-len+2)]));
        }
    }
    if (len == 2) {
        ch3 += 10*(number_char(ip[(sym-len)]));
        ch3 += 1*(number_char(ip[(sym-len+1)]));
    }
    if (len == 1) {
        ch3 += 1*(number_char(ip[(sym-len)]));
    }
    sym++;  // add fot '.' element
    temp = sym; // start position for next cycle
    add1.mas[2] = ch3;

    for (i=temp, len=0; i<=(temp+3); i++) {  // cycle for first number in ip
        if (ip[i] == '\0')
            break;
        if (ip[i] == '-') {
            printf("%s incorrect data!\n\r", ip);
            return erorr;
        }
        if (ip[i] != '.') {  // stops if receives '.'
            if (a=isalpha(ip[i]) == 0) {  // if not correct ip exit with -1
                 len++;
                 sym++;
            }
            else {
                printf("%s incorrect data!\n\r", ip);
                return erorr;
            }
        }
        else
            break;
    }
    if (len > 3 || len < 1) {
        printf("%s incorrect data!\n\r", ip);
        return erorr;
    }
    if (len == 3) {
        if ((a = number_char(ip[0])) > 2) {
            printf("%s incorrect data!\n\r", ip);
            return erorr;
        }
        else {
            ch4 += 100*(number_char(ip[(sym-len)]));
            ch4 += 10*(number_char(ip[(sym-len+1)]));
            ch4 += 1*(number_char(ip[(sym-len+2)]));
        }
    }
    if (len == 2) {
        ch4 += 10*(number_char(ip[(sym-len)]));
        ch4 += 1*(number_char(ip[(sym-len+1)]));
    }
    if (len == 1) {
        ch4 += 1*(number_char(ip[(sym-len)]));
    }
    add1.mas[3] = ch4;

    return add1;
}

int number_char(const char s) {
    int a = 0;
    if (s == '0')
        return 0;
    if (s == '1')
        return 1;
    if (s == '2')
        return 2;
    if (s == '3')
        return 3;
    if (s == '4')
        return 4;
    if (s == '5')
        return 5;
    if (s == '6')
        return 6;
    if (s == '7')
        return 7;
    if (s == '8')
        return 8;
    if (s == '9')
        return 9;
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