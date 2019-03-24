#include<iostream>
using namespace std;

int main()
{
    int n;
    for(int i=0; i<2;i++)
    {
    cin>>n;

    if(n<9){
    switch(n){
        case 1: cout<<"one"; break;
        case 2: cout<<"two"; break;
        case 3: cout<<"three"; break;
        case 4: cout<<"four"; break;
        case 5: cout<<"five"; break;
        case 6: cout<<"six"; break;
        case 7: cout<<"seven"; break;
        case 8: cout<<"eight"; break;
        case 9: cout<<"nine"; break;

    }
    cout<<endl;
    }
        else if(n>9,n%2==0){
            cout<<"even number"<<endl;
        }
        else{

            cout<<"odd number"<<endl;
        }
    }
        return 0;

    }

