#ifndef __UPDATE_H__
#define __UPDATE_H__

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Sort.h"
#include "Robot.h"
#include "Info.h"
#include "Cn.h"
#include "Cnn.h"
#include "Task.h"

using namespace std;

int getNum(Sort sort[], string name, string color, int sortNum);

void updateInfo(Info info[], Sort sort[], Robot &robot, int infoNum, int sortNum);

void updateCn(Cn cn[], Sort sort[], Robot &robot, int cnNum, int sortNum);

void updateCnn(Cnn cnn[], Sort sort[], Robot &robot, int cnnNum,int sortNum);

void showScence(Sort sort[],Robot &robot,int sortNum);


















#endif