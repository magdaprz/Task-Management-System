#include <iostream>
#include <string>
using namespace std;

int main(){

string a;
string b;
cin>>a>>b;
int len1;
int len2;
len1 = a.size();
len2 = b.size();
cout<<len1<<" "<<len2<<endl;
string ab;
ab=a+b;
cout<<ab<<endl;
swap(a[0],b[0]);
cout<<a<<" "<<b;
return 0;
}
