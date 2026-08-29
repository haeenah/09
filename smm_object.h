#ifndef SMM_OBJECT_H
#define SMM_OBJECT_H

#define SMMNODE_TYPE_LECTURE      0
#define SMMNODE_TYPE_RESTAURANT   1
#define SMMNODE_TYPE_LABORATORY   2
#define SMMNODE_TYPE_HOME         3
#define SMMNODE_TYPE_GOTOLAB      4
#define SMMNODE_TYPE_FOODCHANCE   5
#define SMMNODE_TYPE_FESTIVAL     6

void smmObj_addNode(char* name, int type, int credit, int energy);
char* smmObj_getNodeName(int node_nr);
int smmObj_getNodeType(int node_nr);
int smmObj_getNodeCredit(int node_nr);
int smmObj_getNodeEnergy(int node_nr);
char* smmObj_getTypeName(int type);

#endif