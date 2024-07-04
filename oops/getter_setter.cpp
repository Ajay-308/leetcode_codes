#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream> 

using namespace std;

class Student{
    //if this is private and we have to access private member outside the class 
    //other make it public we can use funtion for this
    //getter and setter
    int roll;
    string name;
    float marks;
    public:
    void setRoll(int r){// work as setter name is not fixed you can use any name 
        roll=r;
    }
    int getRoll(){
        return roll;
    }
    void setName(string n){
        name=n;
    }
    string Marks(){ // work as getter --> return name here but i name it as marks 
        return name;
    }
};

int main(){
    Student s1;
    s1.setRoll(5);
    cout<<s1.getRoll()<<endl;
    s1.setName("rahul");
    cout<<s1.Marks()<<endl;
    return 0;
}