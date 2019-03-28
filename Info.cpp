#include "Info.h"

Info::Info()
{
    nameX = "";
    nameY = "";

    colorX = "";
    colorY = "";

    act = "";
}
Info::~Info() {}

void Info::setAct(string _act)
{
    act = _act;
}

string Info::getAct()
{
    return act;
}

void Info::setNamex(string _namex)
{
    nameX = _namex;
}

string Info::getNamex()
{
    return nameX;
}

void Info::setNamey(string _namey)
{
    nameY = _namey;
}

string Info::getNamey()
{
    return nameY;
}

void Info::setColorx(string _colorx)
{
    colorX = _colorx;
}
string Info::getColorx()
{
    return colorX;
}

void Info::setColory(string _colory)
{
    colorY = _colory;
}

string Info::getColory()
{
    return colorY;
}

void Info::show()
{
    cout<<getAct()<<"---"<<getNamex()<<"---"<<getColorx()<<"---"<<getNamey()<<"---"<<getColory()<<endl;
}
