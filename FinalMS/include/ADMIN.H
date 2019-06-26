#ifndef ADMIN_H
#define ADMIN_H

#include<string>
#include "Member.h"
using namespace std;
class Admin
{
    public:
    string name;
    int eid;
    public:
        Admin(string n, int id);
        void createTask();
        void addMembers();

    protected:

    private:
};

#endif // ADMIN_H
