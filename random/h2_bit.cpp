#include <iostream>
#include<math.h>
using namespace std;

int main(){
    int n,r;
    cin>>n>>r;
    int i=0;
    int ans=0;
    int count=0;
    int power=0;
    int b=0;
    int j=0;

    while(n!=0){
        int bit =n&1;
        if(bit==1){
            count++;
        }
        ans+=(bit *pow(10,i));

        n=n>>1;
        i++;
    }
    cout<<ans<<endl<<count<<endl;
    while(r!=0){
        int bit=r&1;
        if(bit==1){
            power++;
        }
        b+=(bit*pow(10,j));
        r=r>>1;
        j++;
        
    }
    int final=power+count;
    cout<<b<<endl<<final<<endl;

}