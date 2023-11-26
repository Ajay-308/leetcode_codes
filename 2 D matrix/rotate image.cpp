class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col =  matrix[0].size();
        vector<vector<int>> ans(row,vector<int>(col));
        int n= col;
        for(int i= 0; i<row; i++){
            for(int j= 0; j<col ;j++){
                ans[i][j]=matrix[n-1][i];
                n--;
            }
            n=col;

        }
        for(int i= 0; i<row; i++){
            for(int j= 0; j<col ;j++){
                matrix[i][j]=ans[i][j];
            }

        }

        
    }
};
