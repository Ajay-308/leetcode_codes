#include <stdio.h>
#include <iostream>

using namespace std;

//creating a class
 class Box{

    private:
    long long length;
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
    Box *king = new Box();
    cout<<"length of box is "<<sizeof(king->getLenth())<<endl;
}