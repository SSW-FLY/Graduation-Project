#include "update.h"

int getNum(Sort sort[], string name, string color, int sortNum) ///////获取编号；///使用Info，Cn,Cnn
{
    int i;
    for (i = 1; i <= sortNum; i++)
    {
        if (sort[i].getName() == name) ///同名
        {
            if (color == "") ////颜色为空不用匹配颜色
            {
                return i;
            }
            else /////颜色不为空匹配颜色
            {
                if (sort[i].getColor() == color)
                {
                    return i;
                }
            }
        }
    }
    if (i == sortNum + 1)
    { ///////未找到，返回-1
        return -1;
    }
}

void updateInfo(Info info[], Sort sort[], Robot &robot, int infoNum, int sortNum)
{
    int i, numX = 0, numY = 0;
    //cout << "infoNum" << infoNum << endl;
    for (i = 0; i < infoNum; i++)
    {
        numX = getNum(sort, info[i].getNamex(), info[i].getColorx(), sortNum);
        numY = getNum(sort, info[i].getNamey(), info[i].getColory(), sortNum);
        //cout << numX << endl;
        //cout << numY << endl;
        //cout << "-----------------" << endl;
        if (numX != -1)
        {

            if (info[i].getAct() == "at") ////x在y位置
            {
                int loc = sort[numY].getLoc();
                sort[numX].setloc(loc);
            }
            else if (info[i].getAct() == "on") ////x在y上
            {
                //cout << "-----on1------------" << endl;
                int loc = sort[numY].getLoc();
                sort[numX].setloc(loc);
                //cout << "-----on2------------" << endl;
            }
            else if (info[i].getAct() == "inside") ////x在y中
            {
                int loc = sort[numY].getLoc();
                sort[numX].setinside(numY);
                sort[numX].setloc(loc);
            }
            else if (info[i].getAct() == "plate") //////物体在机器人手中
            {
                int loc = robot.getLoc();
                sort[numX].setloc(loc);
                robot.setPlate(numX);
            }
            else if (info[i].getAct() == "hold") //////物体在机器人手中
            {
                int loc = robot.getLoc();
                sort[numX].setloc(loc);
                robot.setHold(numX);
            }
            else if (info[i].getAct() == "opened") /////x 开门
            {
                //cout << "-----opened1------------" << endl;
                sort[numX].setopened(true);
                //cout << "-----opened------------" << endl;
            }
            else if (info[i].getAct() == "closed") ////x 关门
            {
                //cout << "-----closed1------------" << endl;
                sort[numX].setopened(false);
                //cout << "-----closed2------------" << endl;
            }
            else ///出现错误不做处理
            {
            }
        }
        else
        {
            cout << "题目有误Info" << endl;
        }
    }
}

void updateCn(Cn cn[], Sort sort[], Robot &robot, int cnNum, int sortNum)
{
    int i, numX = 0, numY = 0;
    for (i = 0; i < cnNum; i++)
    {
        numX = getNum(sort, cn[i].getNamex(), cn[i].getColorx(), sortNum);
        numY = getNum(sort, cn[i].getNamey(), cn[i].getColory(), sortNum);
        if (numX != -1)
        {
            if (cn[i].getType() == "info")
            {
                if (cn[i].getAct() == "at")
                {
                    int loc = sort[numY].getLoc();
                    //sort[numX].setloc(loc);
                    sort[numX].setloc_lock(loc); ////不能去的位置
                    //sort[numX].setmove(false);
                    sort[numX].setlockType("not_on");
                }
                else if (cn[i].getAct() == "on")
                {
                    int loc = sort[numY].getLoc();
                    sort[numX].setloc_lock(loc);
                    sort[numX].setlockType("not_on");
                }
                else if (cn[i].getAct() == "inside") ////x不能放到Y中，先设置锁的类型，在设置lock的位置
                {
                    //int loc = sort[numY].getLoc();
                    sort[numX].setlockType("not_inside");
                    sort[numX].setloc_lock(numY);
                }
                else if (cn[i].getAct() == "plate")
                {
                    //robot.setlockType("not_plate");
                    //robot.setlockPlate(numX);
                    sort[numX].setlockType("not_plate");
                }
                else if (cn[i].getAct() == "hold")
                {
                    sort[numX].setlockType("not_hold");
                    sort[numX].setmove(false);
                }

                else if (cn[i].getAct() == "opened")
                {
                    sort[numX].setdoorlock(true);
                    sort[numX].setopened(false);
                }
                else if (cn[i].getAct() == "closed")
                {
                    sort[numX].setdoorlock(true);
                    sort[numX].setopened(true);
                }

                else ////错误信息不处理
                {
                }
            }
            else if (cn[i].getType() == "task") /////task
            {
                if (cn[i].getAct() == "give")
                {
                    numY = getNum(sort, "human", "", sortNum);
                    int loc = sort[numY].getLoc();
                    sort[numX].setlockType("not_on");
                    sort[numX].setloc_lock(loc);
                }
                else if (cn[i].getAct() == "puton")
                {
                    int loc = sort[numY].getLoc();
                    sort[numX].setlockType("not_on");
                    sort[numX].setloc_lock(loc);
                }
                else if (cn[i].getAct() == "goto")//////可以再做细节处理
                {
                    int loc = sort[numX].getLoc();
                    robot.setLock(loc); ////robot can not go to here
                }
                else if (cn[i].getAct() == "putdown")
                {
                    robot.setlockType("notnot_plate");
                    sort[numX].setlockType("on_plate");
                    sort[numX].setloc_lock(0);
                }
                else if (cn[i].getAct() == "pickup") /////不能被拿起
                {
                    //cout << numX << "--------------------------------" << endl;
                    int loc = sort[numX].getLoc();
                    sort[numX].setlockType("notnot_on");
                    sort[numX].setloc_lock(loc);
                    sort[numX].setmove(false);
                    //cout << numX << "--------------------------------" << endl;
                }
                else if (cn[i].getAct() == "open")
                {
                    sort[numX].setdoorlock(true);
                    sort[numX].setopened(false);
                }
                else if (cn[i].getAct() == "putin")
                {
                    sort[numX].setlockType("not_inside");

                    sort[numX].setloc_lock(numY);
                }
                else if (cn[i].getAct() == "close")
                {
                    sort[numX].setdoorlock(true);
                    sort[numX].setopened(true);
                }
                else if (cn[i].getAct() == "takeout")
                {
                    sort[numX].setlockType("notnot_inside");
                    sort[numX].setloc_lock(numY);
                }
                else /////错误信息处理
                {
                    /* code */
                }
            }
            else ///错误不做处理
            {
            }
        }
        else
        {
            cout << "题目有误cons_not" << endl;
        }
    }
}

void updateCnn(Cnn cnn[], Sort sort[], Robot &robot, int cnnNum, int sortNum) /////Cnn just info
{
    int i, numX = 0, numY = 0;
    for (i = 0; i < cnnNum; i++)
    {
        numX = getNum(sort, cnn[i].getNamex(), cnn[i].getColorx(), sortNum);
        numY = getNum(sort, cnn[i].getNamey(), cnn[i].getColory(), sortNum);
        if (numX = -1)
        {
            if (cnn[i].getAct() == "at")
            {
                int loc = sort[numY].getLoc();
                sort[numX].setloc(loc);
                sort[numX].setmove(false);
                sort[numX].setlockType("notnot_on");
                sort[numX].setloc_lock(loc);
            }
            else if (cnn[i].getAct() == "on")
            {
                int loc = sort[numY].getLoc();
                sort[numX].setloc(loc);
                sort[numX].setmove(false);
                sort[numX].setlockType("notnot_on");
                sort[numX].setloc_lock(loc);
            }
            else if (cnn[i].getAct() == "inside")
            {
                int loc = sort[numY].getLoc();
                sort[numX].setloc(loc);
                sort[numX].setmove(false);
                sort[numX].setlockType("notnot_inside");
                sort[numX].setloc_lock(numY);
            }
            else if (cnn[i].getAct() == "plate")
            {
                sort[numX].setlockType("notnot_plate");
                sort[numX].setloc_lock(0);
                robot.setlockPlate(numX);
            }
            else if (cnn[i].getAct() == "opened")
            {
                sort[numX].setopened(true);
                sort[numX].setdoorlock(true);
            }
            else if (cnn[i].getAct() == "closed")
            {
                sort[numX].setopened(false);
                sort[numX].setdoorlock(true);
            }
            else //////处理错误信息
            {
                /* code */
            }
        }
        else
        {
            cout << "题目有误cons_notnot" << endl;
        }
    }
}

void showScence(Sort sort[], Robot &robot, int sortNum)
{
    cout<<"<<num<<---<<name<<---<<size<<---<<loc<<---<<color<<---<<type<<---<<opened<<---<<move<<endl"<<endl;
    for (int i = 1; i <= sortNum; i++)
    {
        sort[i].show();
    }

    cout << "======================================================================" << endl;
    robot.show();
}
