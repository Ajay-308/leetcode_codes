#include <stdio.h>
#include <iostream>

using namespace std;

//creating a class
 class Box{
    string name;
    int *p;
    public:
    Box(string n){ 
        this->name=n;
        cout<<"constructor called "<<this->name<<endl;
    }
    //destuctors
    //by default destructor is called to free the dynamically allocated memory
    //if u created destrutor then it will not created defualt one 
    ~Box(){  // same name as class but with ~ 
        cout<<"mai tabhai hu "<<name<<endl;

    }

    //constructor call in order and desturctor call in reverse order

 };

int main(){
    // ab object of class Box bana liya
    cout<<"hi"<<endl;
    Box c1("A1"),c2("A2");
}