#ifndef __Sort_h__
#define __Sort_h__
# include<iostream>
# include<string.h>

using namespace std;

class Sort
{
private:
    string name;
    int num;
    string size;
    int loc;
    bool type;//////1 as container
    bool opened;////1 as open
    bool doorlock;
    string color;
    bool used;/// 1 as used
    int loc_lock;//////location  not changed;
    bool move;///////  1 as move
    int inside;
    string lockType;
    
public:
    void setnum(int _num);
    void setname(string _name);
    void setsize(string _size);
    void setloc(int _loc);
    void settype(bool t);
    void setopened(bool t);
    void setcolor(string _color);
    void setused(bool t);
    void setloc_lock(int t);///不能去
    void setmove(bool t);
    void setinside(int num1);
    void setlockType(string lockType);
    void setdoorlock(bool t);

    string getName();
    int getNum();
    string getSize();
    int getLoc();
    bool getType();
    bool getOpened();
    string getColor();
    bool getUsed();
    int getLock();
    bool getMove();
    int getInside();
    string getlockType();
    bool getDoorlock();

    void show();


    Sort(/* args */);
    ~Sort();
};
#endif