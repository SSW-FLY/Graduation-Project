#ifndef __READYTASK_H__
#define __READYTASK_H__

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Info.h"
#include "Task.h"
#include "Cnn.h"
#include "Cn.h"

using namespace std;

void dealTaskstr(string Str, Info info[], Task task[], Cn cn[], Cnn cnn[], int &taskNum, int &infoNum, int &cnNum, int &cnnNum);
void dealwithTask(string str, Task task[], int &taskNum);
void dealwithInfo(string str,Info info[],int &infoNum);
void dealwithCnn(string str, Cnn cnn[], int &cnnNum);
void dealwithCn(string str, Cn cn[], int &cnNum);
string dealAction(string str);

void showInfo(Info info[],int infoNum);

void showCn(Cn cn[],int cnNum);

void showCnn(Cnn cnn[],int cnnNum);

void showTask(Task task[],int taskNum);

#endif