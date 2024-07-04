#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n ,i;

    cin>>n;

    int a1=0;
    int a2=1;

    int next=a1+a2;

    cout<<a1<endl;
    cout<<a2<<endl;
    cout<<next<<endl;

    for(i=3;i<=n;i++){
        a1=a2;
        a2=a1+next;
        next=a1+a2;
        cout<<next<<endl;
    }

return 0;

}