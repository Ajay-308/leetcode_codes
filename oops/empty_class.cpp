#include <stdio.h>
#include <iostream>

using namespace std;

//creating a class
 class Box{

    // how class is empty so it will take 1 byte of memory
 };

int main(){
    // ab object of class Box bana liya
    Box wen;

    //output will be 1
    cout<<"length of the box is:"<<sizeof(wen)<<std::endl;
}