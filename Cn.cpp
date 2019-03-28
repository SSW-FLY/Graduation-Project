#include "Cn.h"

Cn::Cn()
{
    nameX = "";
    nameY = "";

    colorX = "";
    colorY = "";

    act = "";
    type = "";
}
Cn::~Cn(){}

void Cn::setAct(string _act)
{
    act = _act;
}
string Cn::getAct()
{
    return act;
}

void Cn::setNamex(string _namex)
{
    nameX = _namex;
}
string Cn::getNamex()
{
    return nameX;
}

void Cn::setNamey(string _namey)
{
    nameY = _namey;
}
string Cn::getNamey()
{
    return nameY;
}

void Cn::setColorx(string _colorx)
{
    colorX = _colorx;
}
string Cn::getColorx()
{
    return colorX;
}

void Cn::setColory(string _colory)
{
    colorY = _colory;
}
string Cn::getColory()
{
    return colorY;
}

void Cn::setType(string _type)
{
    type = _type;
}
string Cn::getType()
{
    return type;
}

void Cn::show()
{
    cout<<getAct()<<"---"<<getNamex()<<"---"<<getColorx()<<"---"<<getNamey()<<"---"<<getColory()<<endl;
}