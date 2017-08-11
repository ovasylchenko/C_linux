#include <stdio.h>

size_t _strlen(const char *s);
size_t _strnlen(const char *s, size_t maxlen);

size_t _strlen(const char *s) {
/* function return length of string*/

    char *p;
    p =(char*)s; // making cast
    int length = 0;
    if (s != NULL) {
        while (*p++) {
            length++;
        }
    }
    return length;
}
size_t _strnlen(const char *s, size_t maxlen) {
    /* function return length of string, read max size_t length*/

    char *p;
    p =(char*)s;  // making cast
    int symbols, sym_count;
    int i = 0;
    int length = 0;
    if (s != NULL) {
        sym_count = maxlen/sizeof(char);
        while (*p++) {
            if (i < sym_count) {
                length++;
                i++;
            }
        }
    }
    return length;
}
int main(void) {
    char *s = "Hello world!";
    int len, len2;
    len = _strlen(s);
    printf("length(\"%s\") = %d\n", s, len);
    len2 = _strnlen(s, 24);
    printf("length(\"%s\") = %d\n", s, len2);
    return 0;
}

