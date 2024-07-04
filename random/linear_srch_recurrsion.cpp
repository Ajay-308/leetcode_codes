#include<iostream>
using namespace std;

bool linsrch(int arr[],int size, int trt){
    //base case
    if(size==0){
        return false;
    }
    if(arr[0]==trt){
        return true;
    }
    else{
        bool remainingPart=linsrch(arr+1,size-1,trt);
        return remainingPart;

    }

}

int main() {
    int arr[5]={4,2,5,6,1};
    int size=5;
    int trt=6;
    bool ans= linsrch(arr,size,trt);

    if(ans){
        cout<<"present "<<endl;
    }
    else{
        cout<<"absent"<<endl;
    }
return 0;
}