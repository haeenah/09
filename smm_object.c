#include <stdio.h>
#include <string.h>
#include "smm_object.h"

#define MAX_NODE 100

// 캡슐화(Data encapsulation): 외부에서 직접 못 바꾸게 static 전역변수로 보호
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