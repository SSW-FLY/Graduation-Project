/*
 * Simulation@Home Competition
 * File: devil.hpp
 * Author: Cheng Yang
 * Affiliation: HeFei Normal University
 */

#ifndef __home_devil_HPP__
#define __home_devil_HPP__

#include "cserver/plug.hpp"
#include "class.h"

namespace _home
{

    class Devil : public Plug
    {
    public:
        Devil();
        void go(int loc, Sort sort[], Robot &robot);
        void Pickup(int num, Sort sort[], Robot &robot);
        void Putdown(int num, Sort sort[], Robot &robot);
        void Putin(int numX, int numY, Sort sort[], Robot &robot);
        void Takeout(int numX, int numY, Sort sort[], Robot &robot);
        void open(int num, Sort sort[], Robot &robot);
        void close(int num, Sort sort[], Robot &robot);
        void Puton(int numX, int numY, Sort sort[], Robot &robot);
        void Give(int num, Sort sort[], Robot &robot, int sortNum);

        int  dealTasknum(Sort sort[], string name, string color, int sortNum);
        void setArrLoc(Sort sort[],Task task[],int taskNum,int sortNum);
        //int  dealTasknum(Sort sort[], string name, string color, int sortNum);
         void dealAsk(string str,Sort sort[]);
         void delSort(Sort sort[], int sortNum);
         void planWithNormal(Sort sort[], Robot &robot, Task task[],int taskNum,int sortNum);
         void exchange(Task task[],Task task1[], int taskNum);
         void dealnumY(Sort sort[],Task task[],int sortNum,int taskNum);
         void dealnumX(Sort sort[],Task task[],int sortNum,int taskNum);
         void planWithGraph(Task task[],int path[],int pathNum,int taskNum);
        
    protected:
        void Plan();
        void Fini();
    };//Plug

}//_home

#endif//__home_devil_HPP__
//end of file
