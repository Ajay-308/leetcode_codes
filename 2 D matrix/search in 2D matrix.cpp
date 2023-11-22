class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        int s=0;  //starting index
        int e=row*col-1;    // ending index
        
        int  mid=s+(e-s)/2;
        
        while(s<=e){
            int element=matrix[mid/col][mid%col];
            
            if(element==target){
                return 1;
            }
            if(element<target){
                s=mid+1;
            }
            if(element>target){
                e=mid-1;
            }
            
            mid=s+(e-s)/2;
        }
        
        return 0;
    }
};
