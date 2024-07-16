#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream> 

using namespace std;

class Human{
    public:
    string name;
    int age;
    int weight;


};
class Superman {
    protected:
    string krish;
    int power;
};

class student : public Human{
    public:
    int student_id;
    void display(){
        cout <<"name:"<<name<<endl;
    }
};

class superHuman : protected Superman {
    public:
    void fun(string n, int p){
        krish = n;
        power =p;

    }
    void display(){
        cout <<"name:"<<krish<<endl;
        cout <<"power:"<<power<<endl;
    }
};

int main(){
    student s1;
    s1.name ="john";
    s1.display();
    superHuman s2;
    s2.fun("ajay",100);
    s2.display();

}