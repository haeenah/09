#include <stdio.h>

int main(void) {
    FILE *fp = NULL;
    char word[100];
    int i;

    // 쓰기 모드("w")로 파일 열기
    fp = fopen("sample.txt", "w");
    if (fp == NULL) {
        printf("파일 열기 실패!\n");
        return 1;
    }

    // 3가지 단어를 입력받아 파일에 출력
    for (i = 0; i < 3; i++) {
        printf("input a word:");
        scanf("%s", word);
        fprintf(fp, "%s\n", word);
    }

    // 파일 닫기
    fclose(fp);

    return 0;
}