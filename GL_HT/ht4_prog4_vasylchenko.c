#include <stdio.h>

#define MAX_SIZE_STR 1000
size_t _strlcpy(char *d, const char *s, size_t dsize);

size_t _strlcpy(char *d, const char *s, size_t dsize) {
/*copies no more than dsize - 1 characters from string s to d
and ensures that string d always terminated with '\0'. Function returns length of the s.*/

    size_t res;
    int length_d = 0;
    int length_s = 0;
    int copylen = 0;
    int i = 0;
    int j = 0;
    int n = 0;
    int m = 0;

    if (d != NULL) {  // calculate length d
        while (d[m] != '\0') {
            length_d++;
            m++;
        }
    }
    if (s != NULL) {  // calculate length s
        while (s[n] != '\0') {
            length_s++;
            n++;
        }
    if ((length_s + length_d) >= MAX_SIZE_STR) {
        printf("not enough space to copy s in d\n\r!");
    }
    if (length_s < (dsize - 1)){
        printf("str s have only %d symbols\n\r", length_s);
        copylen = length_s;
    }
    else {
        copylen = dsize - 1;
    }
    for (i = length_d; i < (length_d + copylen); i++, j++) {
        d[i] = s[j];
    }
    d[(i+1)] = '\0';  // ensures that string d always terminated with '\0'
    }
    res = length_s;
    return res;
}
int main(void) {
    char d[MAX_SIZE_STR] = "aaaddcccccccc";
    char s[] = "bbbccc";
    size_t y;
    y = _strlcpy(d, s, 6);
    printf("new line is: %s\nsize of copied line is: %zu\n", d, y);
return 0;
}