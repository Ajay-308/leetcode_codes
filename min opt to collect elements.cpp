class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        vector<int> ans;  
        int cnt = 0; 

        for (int target = 1; target <= k; ++target) {
           
            while (find(ans.begin(), ans.end(), target) == ans.end()) {
                if (nums.empty()) {
                   
                    nums.push_back(target);
                    cnt++;
                } else {

                    int last_element = nums.back();
                    nums.pop_back();
                    ans.push_back(last_element);
                    cnt++;
                }
            }

            
            ans.erase(remove(ans.begin(), ans.end(), target), ans.end());
        }

        return cnt;
    }
};
