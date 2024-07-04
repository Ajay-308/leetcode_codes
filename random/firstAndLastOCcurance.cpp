#include<iostream>
using namespace std;

int first(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int ans=-1;

    int  mid=start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            ans=mid;//store crow bhaaya
            end=mid-1;  //ab piche to dekho piche kon hai
        }

        if(arr[mid]<key){
            start=mid+1;  //aage badh bhai
        }
        else{
            end=mid-1;   //
        }
        mid=start+(end-start)/2;
    }
    return ans;
};
int last(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int ans=-1;

    int  mid=start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            ans=mid;
            end=mid+1;
        }

        if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
};
int main(){
    int arr[6]={2,4,9,9,9,13};
    cout<<"9 at index  "<<first(arr,6,9)<<endl;
    
    return 0;
}