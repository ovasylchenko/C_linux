#include <stdio.h>

char *_strtolower(char *s, size_t len);
char *_strtoupper(char *s, size_t len);

char *_strtolower(char *s, size_t len) {
/*converts all upper case chars in string to lower case*/

    char *ps;
    ps =(char*)s; // making cast
    int i = 0;
    int m = len;
    int length_s = 0;
    if (s != NULL) {
        while (s[i] != '\0') {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 'a' - 'A'; // only for ASCII
            }
            i++;
            if (i == m) {
                break;
            }
        }
    }
    return ps;
}
char *_strtoupper(char *s, size_t len) {
/*converts all lower case chars in string to upper case*/

    char *pss;
    pss =(char*)s; // making cast
    int i = 0;
    int m = len;
    int length_s = 0;
    if (s != NULL) {
        while (s[i] != '\0') {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = s[i] + 'A' - 'a'; // only for ASCII
            }
            i++;
            if (i == m) {
                break;
            }
        }
    }
    return pss;
}
int main(void) {
    char s[] = "bBbcCcAAAsdgfsdgGGG";
    char y, z;
    y = *_strtolower(s, 44);
    printf("%s\n", s);
    z = *_strtoupper(s, 12);
    printf("%s\n", s);
return 0;
}