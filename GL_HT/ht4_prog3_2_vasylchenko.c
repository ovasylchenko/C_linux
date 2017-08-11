#include <stdio.h>

char *_strchr(const char *s, int c);
char *_strrchr(const char *s, int c);

char *_strchr(const char *s,  int c) {
/* search given symbol c in string s and return
pointer to it and NULL when no c is found in entire s */

    char *p;
    char cc = (char)(c);  // to avoid problems with cast
    p =(char*)s;  // making cast
    char *t = NULL;
    int i = 0;
    if (s != NULL) {
        while (s[i] != '\0') {
            if (s[i] == cc)
                return p;
            if (s[i] == '\0')
                return t;
            i++;
            (*p++);
        }
    }
    return t;
}
char *_strrchr(const char *s,  int c) {
/* search given symbol c in string s and return
pointer to it and NULL when no c is found in entire s, starts search from right */

    char cc = (char)(c);    // to avoid problems with cast
    char *p;
    p =(char*)s; // making cast
    char *t = NULL;
    int i = 0;
    if (s != NULL) {
        while (s[i] != '\0') {
            (*p++);
            i++;
        }
        while (i >= 0) {
            if (s[i] == cc)
                return p;
            i--;
            (*p--);
        }
    }
    return t;
}
int main() {
    char s[] = "slkhsfkfksdgfsd";
    char c = 'f';
    char y, z;
    y = *_strchr(s, c);
    z = *_strrchr(s, c);
    printf("%c\n\r%c\n\r", y, z);
return 0;
}
