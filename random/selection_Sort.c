#include <stdio.h>

void display(int *arr, int size){
    for(int i=0; i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void selection(int *arr, int size){
    int swap;
    for(int i=0 ; i<size-1; i++){
        int min=i;
        for(int j=i+1;j<size; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
            swap=arr[i];
            arr[i]=arr[min];
            arr[min]=swap;
        }
    }
}
int main(){
    int arr[]={7,6,5,4,3,2,1};
    int size=7;

    display(arr,size);
    selection(arr,size);
    display(arr,size);

}