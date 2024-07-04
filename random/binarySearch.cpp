#include<iostream>
using namespace std;

int binary(int arr[],int size,int key){
    int start=0;
    int end=size-1;

    int  mid=(start+end)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }

        if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;
};

int main(){
    int arr[6]={2,4,5,7,9,13};

    int index=binary(arr,6,6);

    cout<<"9 at index  "<<index<<endl;
    
    return 0;
}