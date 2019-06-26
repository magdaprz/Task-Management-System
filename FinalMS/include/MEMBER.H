#ifndef MEMBER_H
#define MEMBER_H
#include<iostream>
using namespace std;

#include "Task.h"

class Member
{
public:
    string name;
    int eid;
    Task task;
    public:
        Member();
        void workOnTask();
        void markTaskComplete();

    protected:

    private:
};

#endif // MEMBER_H
