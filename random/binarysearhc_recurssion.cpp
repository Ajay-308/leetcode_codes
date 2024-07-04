#include<iostream>
using namespace std;
int binarysearch(int arr[],int s,int e,int key){
    if(s>e){
        return false;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        return true;
    }
    else if(arr[mid]>key){
        return binarysearch(arr,s,mid-1,key);
    }
    else{
        return binarysearch(arr,mid+1,e,key);
    }
}

int main() {
  int arr[7]={3,5,7,8,14,16,29};
  int size=7;
  int key=8;
  cout<<"present or not "<<binarysearch(arr,0,7,key);
  return 0;
}