class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                int area=min(height[i],height[j])*(j-i);
                maxArea = max(maxArea,area);
            }
        }
        return maxArea;

        
    }
};

//above code is giving TLE


class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int l=0;
        int r=height.size()-1;
        while(l<r){
            int area=min(height[l],height[r])*(r-l);
             maxArea = max(maxArea,area);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;

        
    }
};
