#include "devil.hpp"
#include <iostream>

using namespace _home;
using namespace std;

/**
 * 把所有的不能移动的物体从数组中删除
 *
 * */
void Devil::delSort(Sort sort[], int sortNum)
{
    for (int i = 1; i < sortNum; i++)
    {
        //不能移动的物体Name设为空字符
        if (sort[i].getMove() == false)
        {
            sort[i].setname("");
        }
    }
}


//处理AskLoc后的信息
void Devil::dealAsk(string str, Sort sort[])
{
    int left, right;

    left  = str.find("(");
    right = str.find(")");
    int dou = str.find(","); //逗号

    string type = str.substr(0, left);
    string str2 = str.substr(left + 1, dou - left - 1);
    string str3 = str.substr(dou + 1, right - dou - 1);

    int num1 = atoi(str2.c_str());
    int num2 = atoi(str3.c_str());

    if (type == "inside")
    {
        sort[num1].setinside(num2);
        sort[num1].setloc(sort[num2].getLoc());
    }
    else if (type == "at")
    {
        sort[num1].setloc(num2);
    }
    else ////出错
    {
        /* code */
    }
}


/*通常的任务中有两个物体的话，往往第一个有颜色和名字为小物体，第二个物体通常为
 *大物体，只有名字，没有颜色。
 */
void Devil::exchange(Task task[], Task task1[], int taskNum)
{
    //
    int j = 0;

    for (int i = 0; i < taskNum; i++)
    {
        if ((task[i].getNamex() != "") && (task[i].getColorx() != ""))
        {
            task1[j].setAct(task[i].getAct());

            task1[j].setNamex(task[i].getNamex());
            task1[j].setNamey(task[i].getNamey());

            task1[j].setColorx(task[i].getColorx());
            task1[j].setColory(task[i].getColory());

            task1[j].setNumX(task[i].getNumX());
            task1[j].setNumY(task[i].getNumY());

            task1[j].setlocNumX(task[i].getlocNumX());
            task1[i].setlocNumY(task[i].getlocNumY());
            j++;
        }
    }

    for (int i = 0; i < taskNum; i++)
    {
        if ((task[i].getNamex() != "") && (task[i].getColorx() == ""))
        {
            task1[j].setAct(task[i].getAct());

            task1[j].setNamex(task[i].getNamex());
            task1[j].setNamey(task[i].getNamey());

            task1[j].setColorx(task[i].getColorx());
            task1[j].setColory(task[i].getColory());

            task1[j].setNumX(task[i].getNumX());
            task1[j].setNumY(task[i].getNumY());

            task1[j].setlocNumX(task[i].getlocNumX());
            task1[i].setlocNumY(task[i].getlocNumY());
            j++;
        }
    }
}


//任务中确定Y的编号，Y通常为大物体，没有颜色，且大物体通常只有一个，可以重复使用
void Devil::dealnumY(Sort sort[], Task task[], int sortNum, int taskNum)
{
    for (int i = 0; i < taskNum; i++)
    {
        if (task[i].getNamey() != "")      ///有名`
        {
            if (task[i].getColory() != "") //有色
            {
                for (int j = 1; j <= sortNum; j++)
                {
                    if ((sort[j].getName() == task[i].getNamey()) && (sort[j].getColor() == task[i].getColory()))
                    {
                        task[i].setNumY(j);
                    }
                }
            }
            else if (task[i].getColory() == "")
            {
                for (int j = 1; j <= sortNum; j++)
                {
                    if (sort[j].getName() == task[i].getNamey())
                    {
                        task[i].setNumY(j);
                    }
                }
            }
            else
            {
                /* code */
            }
        }
        else
        {
            /* code */
            task[i].setNumY(-1);
        }
    }
}


/*
 *
 * 任务中确定X的编号,X通常为小物体（），可能有多个，遍历该物体是需要判断多个条件才能确定编号。
 * 小物体依附在大物体上
 * 1.机器人到达该物体，且能拿起该物体
 * 2.该X能与Y在同一个动作中
 * 3.X没有被使用
 * 4.X能移动(不能移动，不会被搜索)
 */
void Devil::dealnumX(Sort sort[], Task task[], int sortNum, int taskNum)
{
    for (int i = 0; i < taskNum; i++)
    {
        if (task[i].getNamex() != "")      //有名
        {
            if (task[i].getColorx() != "") //有色
            {
                for (int j = 0; j < sortNum; j++)
                {
                    if ((sort[j].getName() == task[i].getNamex()) && (sort[j].getColor() == task[i].getColorx()))
                    {
                        if (sort[j].getUsed() == false)
                        {
                            task[i].setNumX(j);
                            sort[j].setused(true);
                        }
                    }
                }
            }
            else if (task[i].getColorx() == "") //无色
            {
                for (int j = 0; j < sortNum; j++)
                {
                    if (sort[j].getName() == task[i].getNamex())
                    {
                        if (sort[j].getUsed() == false)
                        {
                            if (task[i].getAct() == "puton")
                            {
                                if ((sort[j].getlockType() == "not_on") && (sort[j].getLock() == sort[task[i].getNumY()].getLoc()))
                                {
                                    continue;
                                }
                                else
                                {
                                    task[i].setNumX(j);
                                    sort[j].setused(true);
                                }
                            }
                            else if (task[i].getAct() == "putin")
                            {
                                if ((sort[j].getlockType() == "not_inside") && (sort[j].getLock() == task[i].getNumY()))
                                {
                                    continue;
                                }
                                else
                                {
                                    task[i].setNumX(j);
                                    sort[i].setused(true);
                                }
                            }
                            else
                            {
                                //其他的动作因为别的地方的处理，在这里不会被约束
                                //机器人不能去得位置上的物体全部锁死，但一般不会出现这样的位置
                                //
                            }
                        }
                    }
                }
            }
        }
        else
        {
            task[i].setNumX(-1);
        }
    }
}


// 将任务中的对应的物体的位置信息放到task数组
// 第一阶段得到的都是正确的位置信息
//
void Devil::setArrLoc(Sort sort[], Task task[], int taskNum, int sortNum)
{
    int numX = -1, numY = -1;
    int i;

    for (i = 0; i < taskNum; i++)
    {
        numX = task[i].getNumX();
        numY = task[i].getNumY();

        if ((numX != -1) && (numY != -1)) ///两个物体
        {
            if (sort[numX].getLoc() == -1)
            {
                dealAsk(AskLoc(numX), sort);
            }

            if (sort[numY].getLoc() == -1)
            {
                dealAsk(AskLoc(numY), sort);
            }

            task[i].setlocNumX(sort[numX].getLoc());
            task[i].setlocNumY(sort[numY].getLoc());
        }
        else if ((numX != -1) && (numY == -1)) ///只有一个物体
        {
            if (sort[numX].getLoc() == -1)
            {
                dealAsk(AskLoc(numX), sort);
            }
            //numYLoc[i] = sort[numX].getLoc();
            task[i].setlocNumX(sort[numX].getLoc());
        }
        else ///出错不执行
        {
            /* code */
        }
    }
}


void Devil::planWithNormal(Sort sort[], Robot& robot, Task task[], int taskNum, int sortNum)
{
    // cout<<"planWithNormal"<<endl;
    // cout<<taskNum<<endl;
    // cout<<sortNum<<endl;
    // for (int i = 0; i < taskNum; i++)
    // {
    //     cout << task[i].getNumX() << "---" << task[i].getNumY() << task[i].getAct() << endl;
    //     cout << "***---------***" << endl;
    // }
    for (int i = 0; i < taskNum; i++)
    {
        //cout<<task[i].getAct() <<endl;
        if (task[i].getAct() == "give")
        {
            //cout<<"give"<<endl;
            Give(task[i].getNumX(), sort, robot, sortNum);
        }
        else if (task[i].getAct() == "puton")
        {
            //cout<<"puton"<<endl;
            Puton(task[i].getNumX(), task[i].getNumY(), sort, robot);
        }
        else if (task[i].getAct() == "pickup")
        {
            //cout<<"pickup"<<endl;
            Pickup(task[i].getNumX(), sort, robot);
        }
        else if (task[i].getAct() == "putdown")
        {
            //cout<<"putdown"<<endl;
            Putdown(task[i].getNumX(), sort, robot);
        }
        else if (task[i].getAct() == "open")
        {
            //cout<<"open"<<endl;
            open(task[i].getNumX(), sort, robot);
        }
        else if (task[i].getAct() == "close")
        {
            //cout<<"close"<<endl;
            close(task[i].getNumX(), sort, robot);
        }
        else if (task[i].getAct() == "takeout")
        {
            //cout<<"takeout"<<endl;
            Puton(task[i].getNumX(), task[i].getNumY(), sort, robot);
        }
        else if (task[i].getAct() == "putin")
        {
            //cout<<"putin"<<endl;
            Putin(task[i].getNumX(), task[i].getNumY(), sort, robot);
        }
        else if (task[i].getAct() == "goto")
        {
            //cout<<"goto"<<endl;
            go(task[i].getlocNumX(), sort, robot);
        }
        else ////
        {
            /* code */
            cout << "任务出错" << endl;
        }
    }
}


void Devil::planWithGraph(Task task[], int path[], int pathNum, int taskNum, Sort sort[], Robot& robot)
{
    //默认空手
    for (int i = 0; i < pathNum; i++)
    {
        for (int j = 0; j < taskNum; j++)
        {
            //与任务中Y的位置相同
            if (path[i] == task[j].getlocNumY())
            {
                int numX = task[j].getNumX();
                int numY = task[j].getNumY();
                go(path[i], sort, robot);
                if (task[j].getAct() == "putin")
                {
                    if (robot.getHold() == task[j].getNumX())
                    {
                        ///门没开,先开门
                        if (!sort[numY].getOpened())
                        {
                            PutDown(numX);
                            robot.setHold(0);

                            Open(numY);
                            sort[numY].setopened(1);

                            PickUp(numX);
                            robot.setHold(numX);
                        }
                        PutIn(numX, numY);
                        sort[numX].setinside(numY);
                        robot.setHold(0);
                    }
                    else if (robot.getPlate() == task[j].getNumX())
                    {
                        int hold = robot.getHold();
                        //手上有东西
                        if (hold != 0)
                        {
                            PutDown(hold);
                            robot.setHold(0);
                            if (!sort[numY].getOpened())
                            {
                                Open(numY);
                                sort[numY].setopened(1);
                            }
                            FromPlate(numX);
                            robot.setPlate(0);
                            robot.setHold(numX);

                            PutIn(numX, numY);
                            sort[numX].setinside(numY);
                            robot.setHold(0);

                            //放下的拿起来
                            PickUp(hold);
                            robot.setHold(hold);
                        }
                        else ///手上没东西
                        {
                            if (!sort[numY].getOpened())
                            {
                                Open(numY);
                                sort[numY].setopened(1);
                            }
                            FromPlate(numX);
                            robot.setPlate(0);
                            robot.setHold(numX);

                            PutIn(numX, numY);
                            sort[numY].setinside(numY);
                            robot.setHold(0);
                        }
                    }
                    else //错误
                    {
                    }
                }
                else if (task[i].getAct() == "puton")
                {
                    int plate = robot.getPlate();
                    int hold  = robot.getHold();
                    if (hold == task[j].getNumX())
                    {
                        PutDown(hold);
                        robot.setHold(0);
                    }
                    else if (Plate == task[j].getNumX())
                    {
                        if (hold != 0)
                        {
                            PutDown(hold);
                            robot.setHold(0);

                            FromPlate(plate);
                            robot.setPlate(0);
                            robot.setHold(hold);

                            PutDown(plate);
                            robot.setHold(0);

                            PickUp(hold);
                            robot.setHold(hold);
                        }
                        else
                        {
                            FromPlate(plate);
                            robot.setHold(plate);
                            robot.setPlate(0);

                            PutDown(plate);
                            robot.setHold(0);
                        }
                    }
                    else
                    {
                    }
                }
                else if (task[i].getAct() == "give")
                {
                }

                //拿出来然后放下
                else if (task[i].getAct() == "takeout")
                {
                    int plate = robot.getPlate();
                    int hold  = robot.getHold();
                    if (hold != 0)
                    {
                        PutDown(hold);
                        robot.setHold(0);

                        if (!sort[numY].getOpened())
                        {
                            Open(numY);
                            sort[numY].setopened(1);
                        }
                        TakeOut(numX, numY);
                        sort[numX].setinside(0);
                        robot.setHold(numX);

                        PutDown(numX);
                        robot.setHold(0);

                        PickUp(hold);
                        robot.setHold(hold);
                    }
                    else
                    {
                        if (!sort[numY].getOpened())
                        {
                            Open(numY);
                            sort[numY].setopened(1);
                        }
                        TakeOut(numX, numY);
                        sort[numX].setinside(0);
                        robot.setHold(numX);

                        PutDown(numX);
                        robot.setHold(0);
                    }
                }
                else //除了这几个动作，其他动作没有Y；
                {
                }
            }
        }

        for (int j = 0; j < taskNum; j++)
        {
            if ((path[i] == task[j].getlocNumX()) && (task[j].getNumY() == -1))
            {
                int numX = task[j].getNumX();
                go(path[i], sort, robot);
                int plate = robot.getPlate();
                int hold  = robot.getHold();
                if (task[j].getAct() == "putdown")
                {
                    if (hold == task[j].getNumX)
                    {
                        PutDown(hold);
                        robot.setHold(0);
                    }
                    else if (plate == task[j].getNumX())
                    {
                        if (hold != 0)
                        {
                            PutDown(hold);
                            robot.setHold(0);

                            FromPlate(plate);
                            robot.setPlate(0);
                            robot.setHold(0);

                            PutDown(plate);
                            robot.setHold(0);

                            PickUp(hold);
                            robot.setHold(hold);
                        }
                        else
                        {
                            FromPlate(plate);
                            robot.setPlate(0);
                            robot.setHold(0);

                            PutDown(plate);
                            robot.setHold(0);
                        }
                    }
                    else
                    {
                    }
                }
                else if (task[j].getAct() == "open")
                {
                    if (sort[numX].getOpened() == false)
                    {
                        if (hold != 0)
                        {
                            PutDown(hold);
                            robot.setHold(0);

                            Open(numX);
                            sort[numX].setopened(1);

                            PickUp(hold);
                            robot.setHold(hold);
                        }
                        else
                        {
                            Open(numX);
                            sort[numX].setopened(1);
                        }
                    }
                }
                else if (task[j].getAct() == "close")
                {
                    if (sort[numX].getOpened() == true)
                    {
                        if (hold != 0)
                        {
                            PutDown(hold);
                            robot.setHold(0);

                            Close(numX);
                            sort[numX].setopened(0);

                            PickUp(hold);
                            robot.setHold(hold);
                        }
                        else
                        {
                            Close(numX);
                            sort[numX].setopened(0);
                        }
                    }
                }
                else if (task[j].getAct() == "go")
                {
                    int loc = sort[numX].getLoc();
                    Move(loc);
                }
                else if (task[j].getAct() == "pickup")
                {
                    if (hold == 0)
                    {
                        PickUp(numX);
                    }
                    else if (plate == 0)
                    {
                    }
                }
                else
                {
                }
            }
        }

        for (int j = 0; j < taskNum; j++)
        {
            if ((task[j].getlocNumX() == path[i]) && (task[j].getNumY() != -1))
            {
                int plate = robot.getPlate();
                int hold  = robot.getHold();
                go(path[i], sort, robot);
                int numX = task[j].getNumX();
                int numY = task[j].getNumY();
                if (task[j].getAct() == "putin")
                {
                }
                else if (task[j].getAct() == "puton")
                {
                }
                else if (task[j].getAct() == "give")
                {
                }
                else if (task[j].getAct() == "takeout")
                {
                }
                else
                {
                }
            }
        }
    }
}
