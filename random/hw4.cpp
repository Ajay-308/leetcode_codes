#include<iostream>

using namespace std;

int sum(int num[],int n){
    int sum=0;

    for(int i=0;i<n;i++){
        sum=num[i+1]+sum;
    }

    return sum; 
}

int main(){
    int size;
    cin>>size;
    int num[20];
    for(int i=1; i<=size;i++){
        cin>>num[i];
    }
    cout<<"your sum is::"<<sum(num, size)<<endl;
    return 0;
}