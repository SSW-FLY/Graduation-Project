#include "Sort.h"

Sort::Sort()
{
    name = "";//
    num = -1;
    size = "";
    loc = -1;
    type = false;////是否是容器
    color = " ";


    opened = true;///门开
    used = false;///是否被使用
    loc_lock = -1;///锁定在某位置||不能去的位置||锁定在某物体中的编号
    lockType = "";///锁定的类型
    move = true;////can move
    inside = 0;///包含该物体的物体编号
    doorlock = false;///门是否有锁定，锁定不能操作
}

Sort::~Sort()
{
}

void Sort::setname(string _name)
{
    name = _name;
}

void Sort::setnum(int _num)
{
    num = _num;
}

void Sort::setsize(string _size)
{
    size = _size;
}

void Sort::setloc(int _loc)
{
    loc = _loc;
}

void Sort::settype(bool t)
{
    type = t;
}

void Sort::setopened(bool t)
{
    opened = t;
}

void Sort::setcolor(string _color)
{
    color = _color;
}
void Sort::setused(bool t)
{
    used = t;
}
void Sort::setloc_lock(int t)
{
    loc_lock = t;
}
void Sort::setmove(bool t)
{
    move = t;
}

string Sort::getName()
{
    return name;
}
int Sort::getNum()
{
    return num;
}

string Sort::getSize()
{
    return size;
}

int Sort::getLoc()
{
    return loc;
}
bool Sort::getType()
{
    return type;
}
bool Sort::getOpened()
{
    return opened;
}

string Sort::getColor()
{
    return color;
}

bool Sort::getUsed()
{
    return used;
}

int Sort::getLock()
{
    return loc_lock;
}

bool Sort::getMove()
{
    return move;
}

void Sort::setinside(int num1)
{
    inside = num1;
}

int Sort::getInside()
{
    return inside;
}

void Sort::setlockType(string _lockType)
{
    lockType = _lockType;
}

string Sort::getlockType()
{
    return lockType;
}

void Sort::setdoorlock(bool t)
{
    doorlock = t;
}
bool Sort::getDoorlock()
{
    return doorlock;
}

void Sort::show()
{


    cout<<num<<"---"<<name<<"---"<<size<<"---"<<loc<<"---"<<color
    <<"---"<<type<<"---"<<opened<<"---"<<move<<"---"<<used<<endl;
}
