#include<iostream>
#include<vector>
using namespace std;
int main() {

    vector<int> v;
    cout<<"size->"<<v.capacity()<<endl;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    cout<<"size->"<<v.capacity()<<endl;
    cout<<"front::"<<v.front()<<endl;
    cout<<"back::"<<v.back()<<endl;
    v.pop_back();
    cout<<"front::"<<v.back()<<endl;

    return 0;
}