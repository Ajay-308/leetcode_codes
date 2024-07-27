

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


