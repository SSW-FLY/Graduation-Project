#include "graph.h"
#include "Task.h"
void initalMap(Task task[], int taskNum, Map *m)
{
    int count = 0;
    int a = 0;
    //cout<<m->Vn[0].loc<<endl;
    for (int i = 0; i < taskNum; i++)
    {
        //cout<<"--------------------0-------------------"<<endl;
        //判重
        for (int j = 0; j < a; j++)
        {
            //cout<<m->Vn[0].loc<<endl;
            //cout<<"--------------------1-------------------"<<endl;
            if (task[i].getlocNumX() == m->Vn[j].loc)
            {
                count++;
            }
        }
        if (count == 0)
        {
            m->Vn[a].loc = task[i].getlocNumX();
            a++;
            count = 0;
        }
        else
        {
            count = 0;
            continue;
        }
    }

    for (int i = 0; i < taskNum; i++)
    {
        if (task[i].getlocNumY() != -1)
        {
            for (int j = 0; j < a; j++)
            {
                if (task[i].getlocNumY() == m->Vn[j].loc)
                {
                    count++;
                }
            }
            if (count == 0)
            {
                m->Vn[a].loc = task[i].getlocNumY();
                a++;
                count = 0;
            }
            else
            {
                count = 0;
                continue;
            }
        }
        else
        {
            continue;
        }
    }
    m->v = a;
    for (int i = 0; i < m->v; i++)
    {
        //cout << m->Vn[i].loc << " ";
        m->Vn[i].Y = false;
    }
    cout << endl;
}

void dealBoolY(Map *m, Task task[], int taskNum)
{
    for (int i = 0; i < taskNum; i++)
    {
        if (task[i].getlocNumY() != -1)
        {
            for (int j = 0; j < m->v; j++)
            {
                if (task[i].getlocNumY() == m->Vn[j].loc)
                {
                    m->Vn[j].Y = true;
                }
            }
        }
    }
}

void creatMap(Task task[], int taskNum, Map *m)
{
    //将所有出发点相同的路径找出来，放到图中
    for (int i = 0; i < taskNum; i++)
    {
        if (task[i].getNumY() != -1)
        {
            for (int j = 0; j < m->v; j++)
            {
                if (task[i].getlocNumX() == m->Vn[j].loc)
                {
                    //cout << "---------------------1---------------------" << endl;
                    ArcNode *p = new ArcNode;
                    p->loc = task[i].getlocNumY();

                    //p->Y = true;
                    p->pre = j;
                    // cout << "pre:" << j << endl;
                    for (int a = 0; a < m->v; a++)
                    {
                        if (m->Vn[a].loc == p->loc)
                        {
                            p->adjvex = a;
                            //cout<<a<<endl;
                        }
                    }
                    p->nextarc = m->Vn[j].firstarc;
                    m->Vn[j].firstarc = p;
                }
                else
                {
                    continue;
                }
            }
        }
        else
        {
            continue;
        }
    }
}

//找出所有X的数组索引；
//找出只存在与X中而不存在与Y中的索引
void findIndex(Task task[], int index[], int taskNum, Map *m, int *icount)
{
    int count = 0;
    int a = 0;
    int index1 = -1;
    for (int i = 0; i < taskNum; i++)
    {
        index1 = task[i].getlocNumX();
        //cout << "index1 " << index1 << endl;
        for (int j = 0; j < taskNum; j++)
        {
            if (index1 == task[j].getlocNumY())
            {
                count++;
            }
        }
        if (count == 0) ///只在X中存在
        {
            for (int b = 0; b < m->v; b++) //通过遍历找到对应位置在Map中的索引
            {
                if (index1 == m->Vn[b].loc)
                {
                    index[a] = b;
                    //cout << b << endl;
                    a++;
                }
            }
        }
        count = 0;
    }
    *icount = a;
}

/**
 * v表示遍历得起始点
*/
void DFSMap(Map *m, int v, int visited[], int path[], int &pathNum)
{
    ArcNode *p;
    //cout<<"pathNum:"<<pathNum<<endl;
    if (visited[v] == 0)
    {
        if (m->Vn[v].Y = false)
        {
            visited[v] = 1;
        }
        //cout << "***" << m->Vn[v].loc << "***" << endl;
        path[pathNum] = m->Vn[v].loc;
        pathNum++;
        p = m->Vn[v].firstarc;
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                DFSMap(m, p->adjvex, visited, path, pathNum);
            }
            p = p->nextarc;
        }
    }
}

void DFSALL(Map *m, int visited[], int index[], int *icount, int path[], int &pathNum)
{
    for (int i = 0; i < *icount; i++)
    {
        DFSMap(m, index[i], visited, path, pathNum);
    }
}
