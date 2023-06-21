class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i=1;i<matrix.size();i++){
            if(target<matrix[i][0] && target>=matrix[i-1][0]){
                for(int j=0;j<matrix[0].size();j++){
                    if(matrix[i-1][j]==target){return true;}
                }
                return false;
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[matrix.size()-1][i]==target){return true;}
        }
        return false;
    }
};