#include <stdio.h>
#include <string.h>
#include <stdlib.h> // system() 함수 사용

int main(void) {
    system("chcp 65001"); // 콘솔 한글 깨짐 방지

    char str[30] = "happy C programming";

    printf("문자열 \"%s\"의 길이 : %d\n", str, (int)strlen(str));

    return 0;
}