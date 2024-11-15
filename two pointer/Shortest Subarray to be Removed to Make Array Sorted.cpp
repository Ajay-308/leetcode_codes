class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        //lets apply binary search to find it 
        // suru se start karo to jab tak move karo jab tak hume next element current se maximum milta rehe --> esa karke humne suru ke sorted element milte rahengee
        
        // similary piche se start karo prev element current se chota hai to right -- karte jao ese karke piche se bhi sorted element mil jayega 
        int n = arr.size();
        int cnt=0;
        int l = 0 , r = n-1;
        while(l+1<n && arr[l+1]>=arr[l]) l++;
        if(l==n-1) return 0;

        while (r > 0 && arr[r] >= arr[r - 1])  r--;

        int mini = min(n - l - 1, r);
        

        //abhi bhi kuch case ese hai jaise ki suru mai sorted hai but piche jo sorted hai vo alag hai 
        //like 
        //1 2 3 4  or second sorted from behind 2,3 ,5 
        // dono ko combine karke nhi hoga 
        // 1 2 2 3 5 ye hona chiye 

        //iske liye alag se case likhna padega 
        int i = 0, j = r;
        while (i <= l && j < n) {
            if (arr[i] <= arr[j]) {
                mini = min(mini, j - i - 1); 
                i++;
            } else {
                j++;
            }
        }
        return mini;
        
    }
};
