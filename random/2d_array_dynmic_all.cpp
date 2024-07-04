#include<iostream>
using namespace std;
int main() {

int row ,col;

cin>>row>>col;

int** arr=new int*[row];

//creating 2d array
for(int i=0; i<row;i++){
    arr[i]=new int[col];

}

//taking input

for(int j=0; j<row;j++){
    for(int k=0;k<col;k++){
        cin>>arr[j][k];
    }
}

//showing output

for(int j=0; j<row;j++){
    for(int k=0;k<col;k++){
        cout<<arr[j][k]<<endl;
    }
}



return 0;
}