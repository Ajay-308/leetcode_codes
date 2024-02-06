#include <stdio.h>
#include <iostream>

using namespace std;

//creating a class
 class Box{

    private:
    double length=3;
    public:

    //ab mai is length ko access karna chahta hu 
    // toh mai isko getter function se access karunga

    int getLenth(){
        return length;
    }

    int setLength(double len){
        length =  len;
    }
 };

int main(){
    // ab object of class Box bana liya
    Box wen;
    cout<<"length of box is "<<wen.getLenth()<<endl;
    wen.setLength(10);
    cout<<"length of box is "<<wen.getLenth()<<endl;
    //output will be 1
    cout<<"length of the box is:"<<sizeof(wen)<<std::endl;
}