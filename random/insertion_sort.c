#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", A[i]);
    }
    printf("\n");
}

void insertionsort(int *A, int n){
    int temp, j;

    for(int i=0; i<=n-1; i++){
        temp=A[i];
        j=i-1;
        while(j>=0 && A[j]>temp){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
}

int main(){
    int  A[]={5,4,3,7,2,8};

    int n =6;
    printArray(A, n);
    insertionsort(A,n);
    printArray(A, n);
    return 0;
}