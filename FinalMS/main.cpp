#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

#include "Admin.h"
#include "Member.h"

vector<Member> members(5);
Admin admin("Magda",10);

void fillData()
{
    members.clear();
    ifstream ReadMembers;
    ReadMembers.open("./member.csv");
    string line;
    int i=0;
    if (ReadMembers.is_open())
    {
        getline(ReadMembers,line);
        while (getline (ReadMembers,line))
        {
            stringstream s(line);
            //cout<<line<<endl;
            s>>members[i].eid;
            char ch;
            s>>ch;
            s>>members[i++].name;
            //cout<<i-1<<"\t"<<members[i-1].eid<<"\t"<<members[i-1].name<<endl;
        }
        ReadMembers.close();
    }
}

void adminLog()
{
    cout<<"Enter EID: ";
    int eid;
    cin>>eid;
    if(eid==10){
        cout<<"***ADMIN***\n";
        cout<<"1. Add Members\t2.Create Task\n";
        cout<<"Enter your option ( 1 or 2) : ";
        int option;
        cin>>option;
        if(option==1)
            admin.addMembers();
        else if(option ==2){
            admin.createTask();
        }
        else cout<<"Invalid option!!";
    }
    else{
        cout<<"\nIncorrect EID!!!!\n";
    }
}

void memberLog()
{
    cout<<"\n***TEAM MEMBER***\n";
    cout<<"Enter EID: ";
    int eid;
    cin>>eid;
    cout<<"Welcome, "<<members[eid-1].name<<"!"<<endl;

    int option=0;
    vector<Task> tasks;

    ifstream TaskReader;
    TaskReader.open("./tasks.csv");
    string line;
    if (TaskReader.is_open())
    {
        //get the current tasks
        while (getline (TaskReader,line))
        {
            int empID,stat;
            char ch;
            string taskName;
            stringstream s(line);
            s>>stat;
            s>>ch;
            s>>empID;
            s>>ch;
            getline(s,taskName);
            Task temp(stat, empID, taskName);
            if(eid==empID){
                cout<<"The task \""<<taskName<<"\" has been assigned to you\n";
                cout<<"1. Work on Task? \t\t 2. Mark as complete? (Enter 1 or 2): ";
                cin>>option;
                if(option==1) { temp.status=1; cout<<"\nUpdated the status as \"WORK IN PROGRESS!\"";}
                else if(option==2) {temp.status=2; cout<<"\nMARKED AS COMPLETE";}
                else cout<<"\nInvalid option!\n";
            }
            if(option!=2) tasks.push_back(temp);
        }
        TaskReader.close();
    }
    if(option!=0){
        ofstream TaskPublish;
        TaskPublish.open("./tasks.csv",ios::trunc);
        vector<Task>:: iterator itr;
        for(itr=tasks.begin();itr!=tasks.end();itr++){
            Task temp=*itr;
            TaskPublish<<temp.status<<","<<temp.eid<<","<<temp.taskName<< endl;
        }
        TaskPublish.close();
    }
    else { cout<<"You currently have no assigned tasks!\n";}
}

int main()
{
    fillData();
    cout<<"\t***LOGIN***\n";
    cout<<"\t1. Admin\t\t2. Team Member\n\n";
    cout<<"Enter your option ( 1 or 2) : ";
    int option;
    cin>>option;
    if(option==1){
        adminLog();
    }
    else if(option==2){
        memberLog();
    }
    return 0;
}
