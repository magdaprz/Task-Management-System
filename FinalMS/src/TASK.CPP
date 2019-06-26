#include "Task.h"

Task::Task()
{
    //ctor
}

Task::Task(int s, int e, string t)
{
    status=s; //by default status is not started
    taskName=t;
    eid=e;//ctor
}
