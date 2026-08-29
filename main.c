#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARDFILEPATH "marbleBoardConfig.txt"
#define MAX_NODE 100

// ==========================================
// 1. 노드 유형 정의 (MACRO)
// ==========================================
#define SMMNODE_TYPE_LECTURE      0
#define SMMNODE_TYPE_RESTAURANT   1
#define SMMNODE_TYPE_LABORATORY   2
#define SMMNODE_TYPE_HOME         3
#define SMMNODE_TYPE_GOTOLAB      4
#define SMMNODE_TYPE_FOODCHANCE   5
#define SMMNODE_TYPE_FESTIVAL     6

// ==========================================
// 2. Data Encapsulation (캡슐화 전역변수)
// ==========================================
static char smmNodeName[MAX_NODE][100];
static int smmNodeType[MAX_NODE];
static int smmNodeCredit[MAX_NODE];
static int smmNodeEnergy[MAX_NODE];
static int nodeCount = 0;

static char smmNodeTypeName[7][20] = {
    "lecture",
    "restaurant",
    "laboratory",
    "home",
    "gotoLab",
    "foodChance",
    "festival"
};

// ==========================================
// 3. API 함수 구현
// ==========================================
void smmObj_addNode(char* name, int type, int credit, int energy) {
    strcpy(smmNodeName[nodeCount], name);
    smmNodeType[nodeCount] = type;
    smmNodeCredit[nodeCount] = credit;
    smmNodeEnergy[nodeCount] = energy;
    nodeCount++;
}

char* smmObj_getNodeName(int node_nr) { return smmNodeName[node_nr]; }
int smmObj_getNodeType(int node_nr) { return smmNodeType[node_nr]; }
int smmObj_getNodeCredit(int node_nr) { return smmNodeCredit[node_nr]; }
int smmObj_getNodeEnergy(int node_nr) { return smmNodeEnergy[node_nr]; }
char* smmObj_getTypeName(int type) { return smmNodeTypeName[type]; }

// ==========================================
// 4. 메인 함수
// ==========================================
int main(void) {
    system("chcp 65001"); // 한글 깨짐 방지

    FILE *fp;
    char name[100];
    int type, credit, energy;
    int board_nr = 0;

    // 설정 파일 자동 생성
    fp = fopen(BOARDFILEPATH, "w");
    if (fp != NULL) {
        fputs("우리집 3 0 18\n"
              "일반물리1 0 5 7\n"
              "카페 1 0 2\n"
              "신호및시스템 0 7 9\n"
              "점심시간 5 0 0\n"
              "전자기학 0 10 15\n"
              "버거집 1 0 6\n"
              "프로그래밍 0 6 9\n"
              "전자공학실험실 2 0 3\n"
              "물성전자 0 14 18\n"
              "학교축제 6 0 0\n"
              "통신이론 0 18 10\n"
              "실험시간 4 0 0\n"
              "회로이론 0 8 10\n"
              "간식시간 5 0 0\n"
              "전자회로 0 9 11\n", fp);
        fclose(fp);
    }

    // 파일 읽기 -> smmObj_addNode로 캡슐화 데이터에 저장
    fp = fopen(BOARDFILEPATH, "r");
    if (fp == NULL) {
        printf("[ERROR] failed to open %s\n", BOARDFILEPATH);
        return -1;
    }

    printf("Reading board component......\n\n");

    while (fscanf(fp, "%s %d %d %d", name, &type, &credit, &energy) == 4) {
        smmObj_addNode(name, type, credit, energy);
        board_nr++;
    }
    fclose(fp);

    // get 함수를 호출하여 화면에 검증 출력
    for (int i = 0; i < board_nr; i++) {
        printf("노드 %2d : 이름=%-15s | 유형=%-10s | 학점=%d | 에너지=%d\n",
               i + 1,
               smmObj_getNodeName(i),
               smmObj_getTypeName(smmObj_getNodeType(i)),
               smmObj_getNodeCredit(i),
               smmObj_getNodeEnergy(i));
    }

    printf("\nTotal number of board nodes : %d\n", board_nr);

    return 0;
}