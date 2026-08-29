#include <stdio.h>

int main(void) {
    FILE *fp = NULL;
    char c;

    // 읽기 모드("r")로 sample.txt 열기
    fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("파일을 못열음\n");
        return 1;
    }

    // 파일의 끝(EOF)을 만날 때까지 한 글자씩 읽어서 출력
    while ((c = fgetc(fp)) != EOF) {
        putchar(c); // 화면에 한 글자 출력
    }

    // 파일 닫기
    fclose(fp);

    return 0;
}