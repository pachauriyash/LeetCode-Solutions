class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==m){for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(matrix[j][i],matrix[i][j]);
            }
        }}
        else{
            vector<vector<int>>ans(m,vector<int>(n));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    ans[j][i]=matrix[i][j];
                }
            }
            return ans;
        }
        return matrix;
    }
};