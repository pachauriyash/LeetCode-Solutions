class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //for 90degree first transpose then swap columns
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            int left=0;
            int right=matrix.size()-1;
            while(left<right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};