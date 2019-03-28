#ifndef __ACTION_H__
#define __ACTION_H__

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Robot.h"
#include "Sort.h"
#include "cserver/plug.hpp"

using namespace std;

void Puton(int numX,int numY, Sort sort[], Robot &robot);

void go(int loc, Sort sort[], Robot &robot);

void Putdown(int num, Sort sort[], Robot &robot);

void Pickup(int num, Sort sort[], Robot &robot);

void open(int num, Sort sort[], Robot &robot)

void Putin(int numX, int numY, Sort sort[], Robot &robot);

void close(int num, Sort sort[], Robot &robot);

void Takeout(int numX, int numY, Sort sort[], Robot &robot);

void Give(int num, Sort sort[], Robot &robot, int sortNum);

#endif
