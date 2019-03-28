#ifndef __home_READY_H__
#define __home_READY_H__

/*
* 处理sort的字符
**/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Sort.h"
#include "Robot.h"

using namespace std;

void dealwithSort(Sort sort[], string Str, Robot &robot, int &countSort);

void dealsort(Sort sort[], string str, int &countSort);

void dealsize(Sort sort[], string str);

void dealcolor(Sort sort[], string str);

void dealloc(Sort sort[], string str, Robot &robot);

void dealtype(Sort sort[], string str);

void dealopen(Sort sort[], string str);

void dealinside(Sort sort[], string str);

void dealhold(Sort sort[], string str, Robot &robot);

void dealplate(Sort sort[], string str, Robot &robot);

#endif