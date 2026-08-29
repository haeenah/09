#include <stdio.h>

int main(void) {
    int i = 0;
    char str[4];
    
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = '\0';

    // %s로 한 번에 출력
    printf("%s\n", str);

    // while문으로 한 글자씩 출력
    while (str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");

    return 0;
}