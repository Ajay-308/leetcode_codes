#include<iostream>
using namespace std;
int main() {
int arr[]={7,34,22,5,11,3,6};
int n=7;

for (int i=0; i<n-1; i++){
    int  minindex=i;
    for(int j= i+1; j<n ; j++){
        if(arr[j]<arr[minindex]){
            minindex=j;
        }
        swap(arr[minindex],arr[j]);
    }
 }
return 0;
}