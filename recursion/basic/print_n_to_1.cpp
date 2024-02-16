//print 1 to n

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void print(int num, int index){
    if(index <=num){
        cout <<  index <<endl;
        print(num,index+1);

    }


}


int main(){
    int num;
    cout<<"enter a number:";
    cin>> num;
    int index= 1;
    print(num,index);
    return 0;
}