#include <stdio.h>
#include <iostream>

using namespace std;

//creating a class
 class Box{
    string name;
    public:
    Box(){ // constructor which is called automatically at the time of  object creation
        cout<<"constructor called"<<endl;
    }
    //parameterized constructor
    Box(string n){
       // name =n; //currently ye parameterized constructor me jo scope hai uska name hai but mai chahta hu ki class ka name ho 
        //so mai class ka name use karne ke liye this keyword use karunga
        this->name =n ;
        cout<<"parameterized constructor called"<<endl;
        cout<<this->name<<endl;
        //this keyword is a pointer which points to the object of the class
    }
 };

int main(){
    // ab object of class Box bana liya
    cout<<"hi"<<endl;
    Box c2("ajay");
}