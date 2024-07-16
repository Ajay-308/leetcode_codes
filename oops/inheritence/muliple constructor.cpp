#include <iostream>
using namespace std;

class A {
public:
    int weight;

    A() {
        cout << "A's constructor called" << endl;
    }
};

class B {
public:
    int height;

    B() {
        cout << "B's constructor called" << endl;
    }
};

class C : public B, public A { 
public:
    void fun(int w, int h) {
        weight = w;
        height = h;
    }
    void display(){
        cout<<"weight: "<< weight<<endl;
        cout<<"height: "<< height<<endl;
    }

    C() {
        cout << "C's constructor called" << endl;
    }
};

int main() {
    C c;
    c.fun(20, 30);
    c.display();
    return 0;
}
