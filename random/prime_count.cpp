#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main() {

int n;
int cnt=0;
cin>>n;

for(int i=2;i<n;i++){
    if(isPrime(i)){
        cnt++;
    }
    
}
return 0;
}