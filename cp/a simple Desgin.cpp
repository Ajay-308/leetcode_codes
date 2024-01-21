
//
// Certainly! The line while (t--) is a loop control statement in C++. Let's break it down in an easy way:

// t is a variable that typically represents the number of test cases or the number of times you want to repeat a certain block of code.

// while (t--) is a loop that continues executing the code inside its block as long as the value of t is greater than zero. The -- is a decrement operation, meaning it reduces the value of t by 1 each time the loop runs.
#include <iostream>
#include <stdio.h>

using namespace std;

int sum(int x){
    int s=0;
    while(x>0){
        s+=x%10; // Add the last digit of x to s
        x/=10;  // Remove the last digit from x
    }
    return s;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;
        int ans=x;
        while(sum(ans)%k!=0){
            ans++;
        }
        cout<<ans<<endl;


    }


    return 0;
}

// input 
// 8  - -- > input test case size
// 1 5
// 10 8
// 37 9
// 777 3
// 1235 10
// 1 10

//output 
//5
// 17
// 45
// 777
// 1243
//10


