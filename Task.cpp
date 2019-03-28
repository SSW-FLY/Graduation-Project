#include "Task.h"

Task::Task()
{
    nameX = "";
    nameY = "";

    colorX = "";
    colorY = "";

    act = "";

    numX = -1;
    numY = -1;

    locNumX = -1;
    locNumY = -1;

}
Task::~Task() {}

void Task::setAct(string _act)
{
    act = _act;
}
string Task::getAct()
{
    return act;
}

void Task::setNamex(string _namex)
{
    nameX = _namex;
}
string Task::getNamex()
{
    return nameX;
}

void Task::setNamey(string _namey)
{
    nameY = _namey;
}
string Task::getNamey()
{
    return nameY;
}

void Task::setColorx(string _colorx)
{
    colorX = _colorx;
}
string Task::getColorx()
{
    return colorX;
}

void Task::setColory(string _colory)
{
    colorY = _colory;
}
string Task::getColory()
{
    return colorY;
}

void Task::setNumX(int _numX)
{
    numX = _numX;
}
int Task::getNumX()
{
    return numX;
}

void Task::setNumY(int _numY)
{
    numY = _numY;
}

int Task::getNumY()
{
    return numY;
}

void Task::setlocNumX(int _locNumX)
{
    locNumX = _locNumX;
}

int Task::getlocNumX()
{
    return locNumX;
}

void Task::setlocNumY(int _locNumY)
{
    locNumY = _locNumY;
}

int Task::getlocNumY()
{
    return locNumY;
}

void Task::show()
{
    cout << getAct() << "---" << getNamex() << "---" << getColorx() << "---" << getNamey() << "---" << getColory() << endl;
}
