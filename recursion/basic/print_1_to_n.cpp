#include <iostream>
#include <string>

using namespace std;




void print(int num){
    if(num > 0){
        cout << num <<endl;
        print(num-1);
    }
}




int main(){
    int num;
    cout<<"enter a number:";
    cin>> num;
    print(num);
    return 0;
}