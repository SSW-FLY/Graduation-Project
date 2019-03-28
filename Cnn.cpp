#include "Cnn.h"

Cnn::Cnn()
{
    nameX = "";
    nameY = "";

    colorX = "";
    colorY = "";

    act = "";
    type = "";
}
Cnn::~Cnn() {}

void Cnn::setAct(string _act)
{
    act = _act;
}
string Cnn::getAct()
{
    return act;
}

void Cnn::setNamex(string _namex)
{
    nameX = _namex;
}
string Cnn::getNamex()
{
    return nameX;
}

void Cnn::setNamey(string _namey)
{
    nameY = _namey;
}
string Cnn::getNamey()
{
    return nameY;
}

void Cnn::setColorx(string _colorx)
{
    colorX = _colorx;
}
string Cnn::getColorx()
{
    return colorX;
}

void Cnn::setColory(string _colory)
{
    colorY = _colory;
}
string Cnn::getColory()
{
    return colorY;
}

void Cnn::setType(string _type)
{
    type = _type;
}
string Cnn::getType()
{
    return type;
}

void Cnn::show()
{
    cout<<getAct()<<"---"<<getNamex()<<"---"<<getColorx()<<"---"<<getNamey()<<"---"<<getColory()<<endl;
}
