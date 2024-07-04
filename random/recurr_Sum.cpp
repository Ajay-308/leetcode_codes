#include<iostream>
using namespace std;

int getsum(int *arr, int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int submission=getsum(arr+1,size-1);
    int ans=arr[0]+submission;
    return ans;
}

int main() {
int arr[5]={3,2,5,1,6};
int size=5;

int ans = getsum(arr,size);

cout<<"sum is:-"<<ans<<endl;

return 0;
}