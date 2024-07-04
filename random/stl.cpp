#include<iostream>
#include<array>
using namespace std;
int main() {
    int basic[3]={1,2,3};
    array<int,4>a ={1,2,3,4};
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
    cout<<"2nd element in this array is::"<<a.at(2)<<endl;
    cout<<"array is empty or not check::"<<a.empty()<<endl;

    cout<<"1st element in this array is::"<<a.front()<<endl;
    cout<<"last element in this array is::"<<a.back()<<endl;

    
    return 0;
}