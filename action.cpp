#include "devil.hpp"
#include <iostream>
using namespace _home;
using namespace std;

void Devil::go(int loc, Sort sort[], Robot& robot)
{
    int numHold = 0, numPlate = 0;     ////手上或盘子de物体的编号

    numHold = robot.getHold();
    numHold = robot.getPlate();
    if (robot.getLoc() != loc)
    {
        Move(loc);
        robot.setLoc(loc);
        //////更新robot身上的物体的信息
        if (numHold != 0)
        {
            sort[numHold].setloc(loc);
        }
        if (numPlate != 0)
        {
            sort[numPlate].setloc(loc);
        }
    }
}


// 1.去该物体的位置
// 2.手上若有东西放下
// 3.该物体不在容器中直接拿，若在容器中，则打开容器门，取出物体
void Devil::Pickup(int num, Sort sort[], Robot& robot)
{
    int sortLoc = sort[num].getLoc();

    go(sortLoc, sort, robot); ///先去该物体的位置
    if (robot.getHold() != 0) ////手上有东西,放下
    {                         // 放下手中的物体
        PutDown(robot.getHold());
        robot.setHold(0);
    }
    if (sort[num].getInside() == 0) // 在容器中
    {                               // 空手拿物
        PickUp(num);
        robot.setHold(num);
    }
    else                            // 在容器中
    {
        int numY = sort[num].getInside();

        if (!sort[numY].getOpened())         // 门没开

        {
            Open(numY);
        }
        TakeOut(num, numY);
        sort[num].setinside(0);
        robot.setHold(num);
    }
}


void Devil::Putdown(int num, Sort sort[], Robot& robot)
{
    int numHold = 0, numPlate = 0;     ////手上或盘子de物体的编号

    numHold  = robot.getHold();
    numPlate = robot.getPlate();
    if (num == robot.getHold())
    {
        PutDown(num);
        robot.setHold(0);
    }
    else if (num == robot.getPlate())
    {
        if (robot.getHold() != 0)           ////手不为空
        {
            cout << "手不为空" << endl;
            PutDown(robot.getHold());
            robot.setHold(0);
        }
        FromPlate(robot.getPlate());
        robot.setHold(robot.getPlate());
        robot.setPlate(0);

        PutDown(robot.getHold());
        robot.setHold(0);
    }
    else                            ///东西不在手上
    {
    }
}


///////////////////////////////////////////////////////////////////////////////////
void Devil::Putin(int numX, int numY, Sort sort[], Robot& robot)
{
    int sortLocX = sort[numX].getLoc();
    int sortLocY = sort[numY].getLoc();

    // PickUp(numX); //na

    Pickup(numX, sort, robot);      ///拿

    go(sortLocY, sort, robot);      ///送
    if (!sort[numY].getOpened())    ////门没开
    {
        PutDown(numX);
        robot.setHold(0);

        Open(numY);
        sort[numY].setopened(1);

        PickUp(numX);
        robot.setHold(numX);

        PutIn(numX, numY);
        sort[numX].setinside(numX);
        robot.setHold(0);
    }
    else
    {
        PutIn(numX, numY);
        sort[numX].setinside(numY);
        robot.setHold(0);
    }
}


void Devil::Takeout(int numX, int numY, Sort sort[], Robot& robot)
{
    int sortLocX = sort[numX].getLoc();
    int sortLocY = sort[numY].getLoc();

    if (sort[numX].getInside() == numY)
    {
        ///小物体在大物体中
    }
    {
        go(sortLocY, sort, robot);
        if (robot.getHold() != 0)           ////bukongshou
        {
            PutDown(robot.getHold());
            robot.setHold(0);
        }
        if (!sort[numY].getOpened())           ///kai men
        {
            Open(numY);
            sort[numY].setopened(1);
        }
        TakeOut(numX, numY);
        sort[numX].setinside(0);
        robot.setHold(numX);
    }
}


void Devil::open(int num, Sort sort[], Robot& robot)
{
    int sortLoc = sort[num].getLoc();

    go(sortLoc, sort, robot);
    if (robot.getHold() != 0)       ///手不为空
    {
        PutDown(robot.getHold());
        robot.setHold(0);
    }
    Open(num);
    sort[num].setopened(1);
}


void Devil::close(int num, Sort sort[], Robot& robot)
{
    int sortLoc = sort[num].getLoc();

    go(sortLoc, sort, robot);
    if (robot.getHold() != 0)       ///手不为空
    {
        PutDown(robot.getHold());
        robot.setHold(0);
    }
    Close(num);
    sort[num].setopened(0);
}


void Devil::Puton(int numX, int numY, Sort sort[], Robot& robot)
{
    int sortLocX = sort[numX].getLoc();
    int sortLocY = sort[numY].getLoc();

    go(sortLocX, sort, robot);

    // if (robot.getHold() != 0)
    // {
    // PutDown(robot.getHold());
    // robot.setHold(0);
    // }
    // PickUp(numX); //na

    Pickup(numX, sort, robot);      // 拿
    go(sortLocY, sort, robot);      // 送
    PutDown(numX);
    robot.setHold(0);
}


void Devil::Give(int num, Sort sort[], Robot& robot, int sortNum)
{
    int human;                      // 人的编号
    int sortLocX = sort[num].getLoc();

    // int sortLocY = sort[human].getloc();
    for (human = 1; human <= sortNum; human++)
    {
        if (sort[human].getName() == "human")
        {
            break;
        }
    }
    if (human <= sortNum)
    {
        int sortLocY = sort[human].getLoc();

        Pickup(num, sort, robot);

        go(sortLocY, sort, robot);

        PutDown(num);
        robot.setHold(0);
    }
    else
    {
        /* code */
    }
}
