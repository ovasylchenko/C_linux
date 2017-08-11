#include <stdio.h>
#include <string.h>

int main(void) {
    unsigned char a;
    unsigned char *pc;
    int c = 0x90;

    pc = &a;
    memset(pc, c, sizeof(a));
    printf("%c\n\r", a);
return 0;
}
