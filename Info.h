#ifndef __INFO_H__
#define __INFO_H__

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Info
{
  private:
    string act;
    string nameX;
    string nameY;
    string colorX;
    string colorY;

  public:
    Info();
    ~Info();

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

    void show();
};
#endif
