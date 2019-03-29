#include "readyTask.h"
#include <iostream>
#include <string.h>

/**
 *     获得任务中的动作
*/
string dealAction(string str)
{
    int left = str.find("(");
    int right = str.find(")");
    string action = str.substr(left + 1, right - left - 1);
    int space = action.find(" ");
    action = action.substr(0, space);
    return action;
}

/**
 *    处理每一条任务  
 * `  /(:task (puton X Y) (:cond (sort X can) (color X green) (sort Y table)))
*/
void dealwithTask(string str, Task task[], int &taskNum)
{
    string str1, action;
    int space1, space2, left, right;
    //cout << str << endl;///////(:task (puton X Y) (:cond (sort X can) (color X green) (sort Y table)))

    space1 = str.find(" ");
    str = str.substr(space1 + 1);

    //cout << str << endl;///////(puton X Y) (:cond (sort X can) (color X green) (sort Y table)))

    action = dealAction(str);
    task[taskNum].setAct(action);
    if(action == "give")
    {
        task[taskNum].getNamey("human");
    }

    right = str.find(")");
    str = str.substr(right + 9);
    //cout<<str<<endl;                //(sort X can) (color X green) (sort Y table)))

    left = str.find("(");
    right = str.find(")");

    while (left != -1)
    {
        str1 = str.substr(left + 1, right - left - 1);
        //cout<<str1<<endl;////////sort X can

        str = str.substr(right + 2);
        left = str.find("(");
        right = str.find(")");

        space1 = str1.find(" ");
        space2 = str1.find(" ", space1 + 1);
        string str1_1 = str1.substr(0, space1);
        string str1_2 = str1.substr(space1 + 1, space2 - space1 - 1);
        string str1_3 = str1.substr(space2 + 1);

        if (str1_1 == "sort")
        {
            if (str1_2 == "X")
            {
                task[taskNum].setNamex(str1_3);
            }
            else
            {
                task[taskNum].setNamey(str1_3);
            }
        }
        else if (str1_1 == "color")
        {
            if (str1_2 == "X")
            {
                task[taskNum].setColorx(str1_3);
            }
            else
            {
                task[taskNum].setColory(str1_3);
            }
        }
    }
    taskNum++;
}

/*
    处理每一条Info
    (:info (at X Y) (:cond (sort X can) (sort Y refrigerator)))))
*/
void dealwithInfo(string str, Info info[], int &infoNum)
{
    string str1, action;
    int space1, space2, left, right;

    space1 = str.find(" ");
    str = str.substr(space1 + 1);

    action = dealAction(str);
    info[infoNum].setAct(action);

    right = str.find(")");
    str = str.substr(right + 9);

    left = str.find("(");
    right = str.find(")");

    while (left != -1)
    {
        str1 = str.substr(left + 1, right - left - 1);

        str = str.substr(right + 2);
        left = str.find("(");
        right = str.find(")");

        space1 = str1.find(" ");
        space2 = str1.find(" ", space1 + 1);
        string str1_1 = str1.substr(0, space1);
        string str1_2 = str1.substr(space1 + 1, space2 - space1 - 1);
        string str1_3 = str1.substr(space2 + 1);

        if (str1_1 == "sort")
        {
            if (str1_2 == "X")
            {
                info[infoNum].setNamex(str1_3);
            }
            else
            {
                info[infoNum].setNamey(str1_3);
            }
        }
        else if (str1_1 == "color")
        {
            if (str1_2 == "X")
            {
                info[infoNum].setColorx(str1_3);
            }
            else
            {
                info[infoNum].setColory(str1_3);
            }
        }
    }
    infoNum++;
}

/*
    处理每一条cons_not
    (:cons_not (:info (at X Y) (:cond (sort X can) (sort Y refrigerator)))))
*/
void dealwithCn(string str, Cn cn[], int &cnNum)
{
    string str1, action, type;
    int space1, space2, left, right;

    space1 = str.find(" ");
    str = str.substr(space1 + 1);

    space1 = str.find(" ");
    type = str.substr(2, space1 - 2);
    cn[cnNum].setType(type);
    str = str.substr(space1 + 1);

    action = dealAction(str);
    cn[cnNum].setAct(action);

    right = str.find(")");
    str = str.substr(right + 9);

    right = str.find(")");
    left = str.find("(");

    while (left != -1)
    {
        str1 = str.substr(left + 1, right - left - 1);

        str = str.substr(right + 2);
        left = str.find("(");
        right = str.find(")");

        space1 = str1.find(" ");
        space2 = str1.find(" ", space1 + 1);
        string str1_1 = str1.substr(0, space1);
        string str1_2 = str1.substr(space1 + 1, space2 - space1 - 1);
        string str1_3 = str1.substr(space2 + 1);

        if (str1_1 == "sort")
        {
            if (str1_2 == "X")
            {
                cn[cnNum].setNamex(str1_3);
            }
            else
            {
                cn[cnNum].setNamey(str1_3);
            }
        }
        else if (str1_1 == "color")
        {
            if (str1_2 == "X")
            {
                cn[cnNum].setColorx(str1_3);
            }
            else
            {
                cn[cnNum].setColory(str1_3);
            }
        }
    }
    cnNum++;
}

/*
    处理每一条cons_not
    (:cons_notnot (:info (at X Y) (:cond (sort X can) (sort Y refrigerator)))))
*/

void dealwithCnn(string str, Cnn cnn[], int &cnnNum)
{
    string str1, action, type;
    int space1, space2, left, right;

    space1 = str.find(" ");
    str = str.substr(space1 + 1);

    space1 = str.find(" ");
    type = str.substr(2, space1 - 2);
    cnn[cnnNum].setType(type);
    str = str.substr(space1 + 1);

    action = dealAction(str);
    cnn[cnnNum].setAct(action);

    right = str.find(")");
    str = str.substr(right + 9);

    right = str.find(")");
    left = str.find("(");

    while (left != -1)
    {
        str1 = str.substr(left + 1, right - left - 1);

        str = str.substr(right + 2);
        left = str.find("(");
        right = str.find(")");

        space1 = str1.find(" ");
        space2 = str1.find(" ", space1 + 1);
        string str1_1 = str1.substr(0, space1);
        string str1_2 = str1.substr(space1 + 1, space2 - space1 - 1);
        string str1_3 = str1.substr(space2 + 1);

        if (str1_1 == "sort")
        {
            if (str1_2 == "X")
            {
                cnn[cnnNum].setNamex(str1_3);
            }
            else
            {
                cnn[cnnNum].setNamey(str1_3);
            }
        }
        else if (str1_1 == "color")
        {
            if (str1_2 == "X")
            {
                cnn[cnnNum].setColorx(str1_3);
            }
            else
            {
                cnn[cnnNum].setColory(str1_3);
            }
        }
    }
    cnnNum++;
}

void dealTaskstr(string Str, Info info[], Task task[], Cn cn[], Cnn cnn[], int &taskNum, int &infoNum, int &cnNum, int &cnnNum)
{
    string str, str1, type;
    //cout<<Str<<endl;
    int space = 0, right, space1;
    Str = Str.substr(6);
    //cout << Str << endl;
    //cout << "-------------------------------------------------------------------------------" << endl;
    while (space != -1)
    {
        right = Str.find(")))");
        space = Str.find(" ", right);
        str = Str.substr(0, space);
        Str = Str.substr(space + 1);

        //cout << Str << endl;

        space1 = str.find(" ");
        type = str.substr(0, space1);
        //cout<<type<<endl;

        if (type.find("task") != -1)
        {
            //cout << "Task"<< endl;
            dealwithTask(str, task, taskNum);
        }

        else if (type.find("info") != -1)
        {
            //cout<<"Info"<<endl;
            dealwithInfo(str, info, infoNum);
        }
        else if (type.find("cons_notnot") != -1)
        {
            //cout<<"Cnn"<<endl;
            dealwithCnn(str, cnn, cnnNum);
        }

        else if (type.find("cons_not") != -1)
        {
            //cout<<"Cn"<<endl;
            //cout<<"----------"<<type<<endl;
            dealwithCn(str, cn, cnNum);
        }
        else
        {
        }
    }
    //cout << "-------------------------------------------------------------------------------" << endl;
}

void showInfo(Info info[], int infoNum)
{
    cout << "*********Info--------------------------------------" << endl;
    for (int i = 0; i < infoNum; i++)
    {
        info[i].show();
    }
}

void showCn(Cn cn[], int cnNum)
{
    cout << "*********Cn--------------------------------------" << endl;
    for (int i = 0; i < cnNum; i++)
    {
        cn[i].show();
    }
}

void showCnn(Cnn cnn[], int cnnNum)
{
    cout << "*********Cnn--------------------------------------" << endl;
    for (int i = 0; i < cnnNum; i++)
    {
        cnn[i].show();
    }
}

void showTask(Task task[], int taskNum)
{
    cout << "*********Task--------------------------------------" << endl;
    for (int i = 0; i < taskNum; i++)
    {
        task[i].show();
    }
}
