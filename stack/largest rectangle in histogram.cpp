class Solution {
public:
   //find next smaller element 
    vector<int> nextSmallest (vector<int> & ans){
        int n= ans.size(), num=0;
        vector<int> v(n);
        stack<int> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            num=ans[i];
            while(s.top()!=-1 && ans[s.top()]>=num){
                s.pop();
            }
            v[i]=s.top();
            s.push(i);
        }
        return v;

    }
    //finding prev smaller
    vector<int> prevSmallest(vector<int> & ans){
        int n= ans.size(), num=0;
        vector<int> v(n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            num=ans[i];
            while(s.top()!=-1 && ans[s.top()]>=num){
                s.pop();
            }
            v[i]=s.top();
            s.push(i);
        }
        return v;

    }
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size() ,h ,l , area=0, totalArea;
        vector<int> next= nextSmallest(heights); 
        vector<int> prev= prevSmallest(heights);
        for(int i=0; i<size;i++){
            if(next[i]== -1) next[i]=size;
            l= next[i]-prev[i]-1;
            totalArea = l * heights[i];
            area= max(area,totalArea);
        }
        return area;
        
    }
};
