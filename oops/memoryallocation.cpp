#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream> 

using namespace std;

class Student{
    ///  1 byte for char + 4 byte for int = 5 byte
    //but it will take 8 byte because of padding 
    //padding-> compiler will add some extra byte to make it multiple of 4
    // why do so because it will be easy to access the memory

    //cpu will access the memory in multiple of 4 (32bit system) and decode it  --> so it will be easy to access the memoy in multiple of 4
    char c;
    int a;
};

int main(){
    Student s1;
    cout<<sizeof(s1);
    return 0;
}