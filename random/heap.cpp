#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<k && i<m; i++)
        minHeap.push(nums1[i]);
    for(int i=0; i<k && i<n; i++)
        minHeap.push(nums2[i]);

    for(int i=k; i<m+n; i++) {
        if(nums1[i%m] < minHeap.top()) {
            minHeap.pop();
            minHeap.push(nums1[i%m]);
        }
        if(nums2[i%n] < minHeap.top()) {
            minHeap.pop();
            minHeap.push(nums2[i%n]);
        }
    }

    return minHeap.top();
}

int main() {
    vector<int> nums1 = {3, 5, 1, 7, 9};
    vector<int> nums2 = {4, 2, 6, 8, 10};

    int k = 4;

    cout << kthSmallest(nums1, nums2, k) << endl;

    return 0;
}
