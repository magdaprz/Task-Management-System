#include "Member.h"

Member::Member()
{
    //ctor
}

void Member:: workOnTask()
{
    task.status=1;
}
void Member::markTaskComplete()
{
    task.status=2;
}
