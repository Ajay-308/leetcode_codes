class Solution {
private:
   void comb(int ind, int target, vector<int> &arr,vector<vector<int>> &ans,vector<int> ds)
   {
       //base case when ind ==arr size ho jaye and target ==0 ho jayega to mujhe ans mai ds ko push karega else return karke aage code badha dega 
        if(ind==arr.size()){
           if(target==0) {
               ans.push_back(ds);
           }

           return;
        }
        //picked
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            comb(ind,target-arr[ind],arr , ans ,ds);
            ds.pop_back();
        }
        //non picked ki condition hai ye
        comb(ind+1,target,arr , ans ,ds);

   }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        comb(0,target,candidates,ans , ds);
        return ans;

        
    }
};
