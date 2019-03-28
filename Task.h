#ifndef __TASK_H__
#define __TASK_H__

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Task
{
  private:
    string act;
    string nameX;
    string nameY;
    string colorX;
    string colorY;
    int numX;
    int numY;

    int locNumX;
    int locNumY;

  public:
    Task();
    ~Task();

    void setAct(string _act);
    string getAct();

    void setNamex(string _namex);
    string getNamex();

    void setNamey(string _namey);
    string getNamey();

    void setColorx(string _colorx);
    string getColorx();

    void setColory(string _colory);
    string getColory();

    void setNumX(int _numX);
    int getNumX();

    void setNumY(int _numY);
    int getNumY();

    void setlocNumX(int _locNumX);
    int getlocNumX();

    void setlocNumY(int _locNumY);
    int getlocNumY();

    void show();
};
#endif
