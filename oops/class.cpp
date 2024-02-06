#include <stdio.h>
#include <iostream>
#include "Box.cpp" // --> this is the file where the class is defined

using namespace std;

//creating a class 

//  class Box{
//     public:
//     double length;
//     double breadth;
//  };

int main(){
    // ab object of class Box bana liya
    Box len;
    Box wen;
    cout<<"length of the box is:"<<len.length<<std::endl;
    cout<<"length of the box is:"<<sizeof(wen)<<std::endl;
}