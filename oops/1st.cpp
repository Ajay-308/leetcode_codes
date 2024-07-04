#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream> 

using namespace std;

class Student{
    //by default private inside this class only we can access inside this class 
    // for make it accessable every where we have to make it public 
    public:
    int roll;
    string name;
    float marks;
};

int main(){
    Student s1;
    s1.roll =1;
    cout<<s1.roll;
    return 0;
}