#ifndef __Robot_h__
#define __Robot_h__
#include <iostream>
#include <string.h>

using namespace std;


class Robot
{
  private:
    int plate;
    int hold;
    int loc;
    int loc_lock;////不能去的位置
    string lockType;////多余///
    int lockPlate;////Plate上固定东西

  public:
    Robot();
    ~Robot();
    void setPlate(int _palte);
    int getPlate();

    void setHold(int _hold);
    int getHold();

    void setLoc(int _loc);
    int getLoc();

    void setLock(int Lock);
    int getLock();

    void setlockType(string _lockType);
    string getlockType();


    void setlockPlate(int _lockPlate);
    int getlockPlate();


    void show();
};
#endif