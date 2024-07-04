#include<iostream>
using namespace std;
int solve(int &nums,int target){
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(target<nums[i]){
            i++;
        }
        else if(target>nums[i]){
            cout<<nums[i-1];
        }
    }
    return 0;


}
int main() {

int arr[]=[1,3,5,7];
int target=2;

cout<<solve(arr,target);




return 0;
}