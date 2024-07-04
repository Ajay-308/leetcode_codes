
#include <iostream>
#include <vector>

using namespace std;

int findMissing(vector<int>& nums) {
    int n = nums.size() + 1;
    int sum = (n * (n+1)) / 2;

    for(int i=0; i<nums.size(); i++)
        sum -= nums[i];

    return sum;
}

int main() {
    vector<int> nums = {1, 2,3, 4, 5, 6,7,9};

    cout << findMissing(nums) << endl;

    return 0;
}
