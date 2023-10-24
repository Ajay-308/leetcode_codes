class Solution {
private:
    void comb(int ind, int n, int k, vector<vector<int>>& ans, vector<int>& ds) {
        // Base case
        if (k == 0 && n == 0) {
            ans.push_back(ds);
            return;
        }
        if (k <= 0 || n <= 0) {
            return;
        }

        // Picked
        for (int i = ind + 1; i <= 9; i++) {
            ds.push_back(i);
            comb(i, n - i, k - 1, ans, ds);
            ds.pop_back(); // Backtrack
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        comb(0,n,k,ans , ds);
        return ans;
        
    }
};
