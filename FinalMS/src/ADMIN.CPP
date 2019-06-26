#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Admin.h"
#include "Task.h"
using namespace std;

Admin::Admin(string n, int id)
{
    name=n;
    eid=id;
}

void Admin:: createTask()
{
    cout<<"\nEnter the eid to assign :";
    int eid,status=0;
    cin>>eid;
    if(eid<1 && eid>5) cout<<"\nInvalid ID!\n";
    string name;
    getline(cin, name);
    ifstream TaskReader;
    TaskReader.open("./tasks.csv");
    string line;
    if (TaskReader.is_open())
    {
        while (getline (TaskReader,line))
        {
            int empID,stat;
            char ch;
            string taskName;
            stringstream s(line);
            s>>stat;
            s>>ch;
            s>>empID;
            getline(s,taskName);
            if(eid==empID){
                cout<<"The EID: "<<eid<<" has been assigned the task \""<<taskName<<"\" already!";
                return;
            }
        }
        TaskReader.close();
    }

    cout<<"Task name: ";
    getline(cin, name);

    ofstream TaskPublish;
    TaskPublish.open("./tasks.csv",ios::app);
    TaskPublish<<status<<","<<eid<<","<<name << endl;
    TaskPublish.close();
    cout<<"\nThe task \""<<name<<"\" has been assigned to member with eid "<<eid<<" succesfully"<<endl;
}

void Admin:: addMembers()
{
    vector<Member> members(5);
    cout<<"Enter the team member names:\n";

    ofstream TeamMembers;
    TeamMembers.open("./member.csv");
    TeamMembers << "EID,Name" << endl;

    for(int i=0;i<5;i++)
    {
        string ename;
        cout<<i+1<<": Name: ";
        cin>>ename;
        members[i].name=ename;
        members[i].eid=i+1;
        TeamMembers << i+1<<","<<ename << endl;
    }
    TeamMembers.close();
    cout<<"Added members successfully"<<endl;
}
