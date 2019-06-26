#ifndef TASK_H
#define TASK_H

#include<iostream>
using namespace std;
class Task
{
public:
    string taskName;
    int status; // 0=not started,1= in progress, 2=completed;
    int eid;

    public:
        Task();
        Task(int s, int e, string t);

    protected:

    private:
};

#endif // TASK_H
