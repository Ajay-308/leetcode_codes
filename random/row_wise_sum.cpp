#include<iostream>
using namespace std;
/// return sum row wise
    // void row_sum(int arr[][3],int row ,int col){

    //     for(int i=0; i<3;i++){
    //         int sum=0;
    //         for(int j=0; j<3;j++){
    //             sum+=arr[i][j];
    //         }
    //         cout<<sum<<endl;
    //     }

    // }



    //return greatest of row sum;

    void greatestSum(int arr[][3],int row ,int col){
        int maxi=INT16_MIN;
        for(int i=0; i<3;i++){
            int sum=0;
            for(int j=0; j<3;j++){
                sum+=arr[i][j];
            }
            cout<<sum<<endl;
            if(sum>maxi){
                maxi=sum;
            }
        }
        cout<<"maximum is"<<maxi<<endl;
    }


int main() {

    int arr[3][3];

    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"your output is "<< endl;
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    greatestSum(arr,3,3);

    //row_sum(arr,3,3);
return 0;
}