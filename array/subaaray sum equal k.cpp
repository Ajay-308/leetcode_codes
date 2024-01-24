class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // this code have three loop tc->  0(n^3); --> give tle

        // int cnt=0;
        // int n =nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int s=0;
        //         for(int k=i;k<=j;k++){
        //             s+=nums[k];

        //         }
        //         if(s==k){
        //             cnt++;
        //         }
        //     }
        // }
        
        // return cnt;

       //better than above one 

        // int cnt=0;
        // int n =nums.size();
        // for(int i=0;i<n;i++){
        //     int s=0;
        //     for(int j=i;j<n;j++){
        //         s+=nums[j];
                
        //         if(s==k){
        //             cnt++;
        //         }
        //     }
        // }
        
        // return cnt;


        //optimal -> using hashing and reverse enginerring
        class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        int sum = 0;
        int count = 0;

        // Initialize the map with sum 0 and count 1 to handle cases where the subarray starts from the beginning
        prefixSumCount[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // Check if (sum - k) exists in the map
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            // Update the map with the current sum
            prefixSumCount[sum]++;
        }

        return count;
    }
};


    }
};
