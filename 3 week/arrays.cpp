#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverse (int tab[], int value){
for(int i=value-1; i>=0; i--){
        cout<<tab[i]<<' ';
    }


}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a;
    cin>>a;
    int tab[a];
    for(int i=0; i<a; i++){
        cin>>tab[i];
    }
    reverse(tab, a);
    return 0;
}
