#include "ready.h"
#include <iostream>
#include <string.h>

void dealsort(Sort sort[], string str,int &countSort) ////num and name
{
    string str1, str2, str3;
    int space1, space2, num;
    space1 = str.find(" ");
    space2 = str.find(" ", space1 + 1);
    str1 = str.substr(0, space1);
    str2 = str.substr(space1 + 1, space2 - space1 - 1);
    str3 = str.substr(space2 + 1);
    num = atoi(str2.c_str());
    if(num >countSort)
    {
        countSort = num;
    }

    sort[num].setnum(num);
    sort[num].setname(str3);
}

void dealsize(Sort sort[], string str) ///size
{
    string str1, str2, str3;
    int space1, space2, num;
    space1 = str.find(" ");
    space2 = str.find(" ", space1 + 1);
    str1 = str.substr(0, space1);
    str2 = str.substr(space1 + 1, space2 - space1 - 1);
    str3 = str.substr(space2 + 1);
    num = atoi(str2.c_str());

    sort[num].setsize(str3);
}

void dealcolor(Sort sort[], string str) /////color
{
    string str1, str2, str3;
    int space1, space2, num;
    space1 = str.find(" ");
    space2 = str.find(" ", space1 + 1);
    str1 = str.substr(0, space1);
    str2 = str.substr(space1 + 1, space2 - space1 - 1);
    str3 = str.substr(space2 + 1);
    num = atoi(str2.c_str());

    sort[num].setcolor(str3);
}

void dealloc(Sort sort[], string str,Robot &robot)
{
    string str1, str2, str3;
    int space1, space2, num, loc;
    space1 = str.find(" ");
    space2 = str.find(" ", space1 + 1);
    str1 = str.substr(0, space1);
    str2 = str.substr(space1 + 1, space2 - space1 - 1);
    str3 = str.substr(space2 + 1);
    num = atoi(str2.c_str());
    loc = atoi(str3.c_str());

    if(num == 0)
    {
        robot.setLoc(loc);
    }

    sort[num].setloc(loc);
}

void dealtype(Sort sort[], string str)
{
    string str1, str2, str3;
    int space1, space2, num;
    space1 = str.find(" ");
    space2 = str.find(" ", space1 + 1);
    str1 = str.substr(0, space1);
    str2 = str.substr(space1 + 1, space2 - space1 - 1);
    str3 = str.substr(space2 + 1);
    num = atoi(str2.c_str());

    sort[num].settype(true);
    sort[num].setsize("big");
}

void dealopen(Sort sort[], string str)
{
    string str1, str2;
    int space1, num;
    space1 = str.find(" ");
    str1 = str.substr(0, space1);
    str2 = str.substr(space1 + 1);

    num = atoi(str2.c_str());

    if (str1 == "opened")
    {
        sort[num].setopened(true);
    }
    else
    {
        sort[num].setopened(false);
    }
}

void dealplate(Sort sort[],string str,Robot &robot)
{
    string str1,str2;
    int space1,plate;
    space1 = str.find(" ");
    str1 = str.substr(0,space1);//type
    str2 = str.substr(space1+1);
    plate = atoi(str2.c_str());

    if(plate != 0)
    {
        robot.setPlate(plate);
        int loc = robot.getLoc();
        sort[plate].setloc(loc);
    }
}

void dealhold(Sort sort[],string str,Robot &robot)
{
    string str1,str2;
    int space1,hold;
    space1 = str.find(" ");
    str1 = str.substr(0,space1);
    str2 = str.substr(space1 +1);
    hold = atoi(str2.c_str());
    if(hold != 0)
    {
        robot.setHold(hold);
        int loc = robot.getLoc();
        sort[hold].setloc(loc);
    }
}

void dealinside(Sort sort[], string str)
{
    string str1, str2, str3;
    int space1, space2, num1, num2;
    space1 = str.find(" ");
    space2 = str.find(" ", space1 + 1);
    str1 = str.substr(0, space1);
    str2 = str.substr(space1 + 1, space2 - space1 - 1);
    str3 = str.substr(space2 + 1);

    num1 = atoi(str2.c_str());////xiao wuti
    num2 = atoi(str3.c_str());////da wuti

    sort[num1].setinside(num2);
    sort[num1].setloc(sort[num2].getLoc());
}

void dealwithSort(Sort sort[], string Str,Robot &robot,int &countSort)
{
    int left, right, space;
    string str, type;
    Str = Str.substr(9);
    left = Str.find("(");
    right = Str.find(")");
    while (left != -1)
    {
        str = Str.substr(left + 1, right - left - 1);
        ///////
        space = str.find(" ");
        type = str.substr(0, space); //////short string type
        ///////jugement
        if (type == "sort")
        {
            dealsort(sort, str,countSort);
        }
        else if (type == "size")
        {
            dealsize(sort, str);
        }
        else if (type == "color")
        {
            dealcolor(sort, str);
        }
        else if (type == "at")
        {
            dealloc(sort, str,robot);
        }
        else if (type == "type")
        {
            dealtype(sort, str);
        }
        else if (type == "opened")
        {
            dealopen(sort, str);
        }

        else if (type == "closed")
        {
            dealopen(sort, str);
        }

        else if (type == "plate")
        {
            dealplate(sort,str,robot);
        }

        else if(type == "hold")
        {
            dealhold(sort,str,robot);
        }

        else if(type == "inside")
        {
            dealinside(sort,str);
        }

        /*cout << str <<",";
        cout<<endl;*/

        Str = Str.substr(right + 2);
        left = Str.find("(");
        right = Str.find(")");
    }
    //cout << "-------------------------------------------------------------------------------" << endl;

    sort[0].setname("robot");
    sort[0].setloc(robot.getLoc());
    // for (int i = 1; i <= countSort; i++)
    // {
    //     sort[i].show();
    // }

    // robot.show();
}
