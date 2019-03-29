/*
 * Simulation@Home Competition
 * File: devil.cpp
 * Author: Cheng Yang
 * Affiliation: HeFei Normal University
 *              
 */

#include "devil.hpp"
#include <iostream>

using namespace _home;
using namespace std;
//////////////////////////////////////////////////////////////////////////
Devil::Devil() : Plug("Devil"){};


//////////////////////////////////////////////////////////////////////////
void Devil::Plan()
{

    int countSort = 0;
    int &cs = countSort;
    Sort sort[50]; 
    Robot robot;
    Robot &r = robot;
    int tasknum = 0,infonum = 0,cnnum = 0,cnnnum = 0;
    int &taskNum = tasknum; 
    int &infoNum = infonum;
    int &cnNum = cnnum;
    int &cnnNum = cnnnum;
    
    Info info[10];
    Task task[10];
    Cn cn[10];
    Cnn cnn[10];
    Task task1[10];
    Map *m = new Map;
    for(int i = 0;i<15;i++)
    {
        m->Vn[i].loc = 0;
        m->Vn[i].firstarc = NULL;
    }


    dealwithSort(sort,GetEnvDes(),r,cs);
    dealTaskstr(GetTaskDes(),info,task,cn,cnn,taskNum,infoNum,cnNum,cnnNum);
    updateInfo(info,sort,r,infonum,countSort);
    updateCn(cn,sort,r,cnnum,countSort);
    updateCnn(cnn,sort,r,cnnnum,countSort);

    // showScence(sort,r,countSort);
    // showInfo(info,infonum);
    // showCn(cn,cnnum);
    // showCnn(cnn,cnnnum);
    // showTask(task,tasknum);

    exchange(task,task1,taskNum);
    delSort(sort,countSort);
    dealnumY(sort,task1,countSort,taskNum);
    dealnumX(sort,task1,countSort,taskNum);
    setArrLoc(sort,task1,taskNum,countSort);
    //planWithNormal(sort,r,task1,tasknum,countSort);
    
    initalMap(task1,taskNum,m);
    dealBoolY(m,task1,taskNum);
    creatMap(task1,taskNum,m);

    int visited[m->v];
    int index[15];
    int *icount = new int; 
    int path[15];
    int pathnum = 0;
    int &pathNum = pathnum;
    for(int i = 0;i<m->v;i++)
    {
        visited[i] = 0;
    }
    findIndex(task1,index,taskNum,m,icount);
    DFSALL(m,visited,index,icount,path,pathNum);//
    cout<<"------------------------"<<endl;
    // for(int i = 0;i<pathNum;i++)
    // {
    //     cout<<path[i]<<endl;
    // }
    planWithGraph(task1,path,pathNum,taskNum,sort,robot);
    


}

void Devil::Fini()
{
    cout << "#(Devil): Fini" << endl;
}
