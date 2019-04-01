#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
void start(){
string a;
cin>>a;
a+=",";
string b="";
for(int i=0; i<a.length(); i++){
    if(a[i]==','){
    cout<<b<<endl;
    b="";
    continue;
	}
	b+=a[i];
}
}
int main() {
start();
	return 0;
}
