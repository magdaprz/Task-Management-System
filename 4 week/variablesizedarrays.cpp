#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n,q;
    cin>>n>>q;
    vector< vector<int> > listOfArrays(n);
    for(int i=0;i<n;i++){
        int size;
        cin>>size;
        vector<int> arr(size);
        for(int j=0;j<size;j++)
            cin>>arr[j];
        listOfArrays[i]=arr;
   }
   int x,y;
   for(int i=0;i<q;i++)
   {
      cin>>x>>y;
      cout<<listOfArrays[x][y]<<endl;
   }
   return 0;
}
