#include <stdio.h>
#include <iostream>

using namespace std;

class Customer{
    string name;
    int ac_no,bal;
    //static variable add karunga
    static int cnt;
    public:
    //constructor
    Customer(string n,int ac, int b){
        this->name=n;
        this->ac_no=ac;
        this->bal=b;
        cnt++;
        cout<<"constructor called :-"<<cnt<<endl; 
    }
};
//static variable ko initialize karna padega na hn meri jaan
int Customer::cnt=0;
int main(){
    //isme meri problem ye hai ki mai chahta hu ki mai inki count rakh payu  abhi koi count nhi hai 
    //to achive this we use static keywrod
    //static keyword is used to create only single copy of class variable and share it among all objects of this class

    Customer c1("A1",1,1000);
    Customer c2("A2",2,2000);

}

