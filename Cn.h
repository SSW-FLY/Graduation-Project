#ifndef __CN_H__
#define __CN_H__

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Cn
{
private:
  string act;
  string nameX;
  string nameY;
  string colorX;
  string colorY;
  string type;

public:
  Cn();
  ~Cn();

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

  void setType(string _type);
  string getType();

  void show();
};
#endif
