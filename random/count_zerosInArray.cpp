#include<iostream>
using namespace std;
int main() {
 int arr[30]={0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1}; //14 -0
 int n=22;
 int count=0;
 for(int i=0;i<n;i++){
    if(arr[i]==0){
        count++;
    }
 }
 cout<<count<<endl;

return 0;
}