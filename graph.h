#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <iostream>
#include <stdlib.h>
#include "Task.h"
typedef struct ANode
{
  int adjvex;
  ANode *nextarc;
  int loc;
  int pre;
}ArcNode;

typedef struct VNode
{
  int loc;
  bool Y;
  ArcNode *firstarc;
}Vnode;


typedef struct
{
    int v;
    int e;
    Vnode Vn[15];
}Map;


void initalMap(Task task[], int taskNum, Map *m);
void dealBoolY(Map *m,Task task[],int taskNum);
void creatMap(Task task[], int taskNum,Map *m);
void  findIndex(Task task[],int index[],int taskNum,Map *m,int *icount);
void DFSMap(Map *m, int v, int visited[], int path[], int &pathNum);
void DFSALL(Map *m, int visited[], int index[], int *icount, int path[], int &pathNum);
#endif