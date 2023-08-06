class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        //return 1;
        vector<int>col(mat[0].size(),0),row(mat.size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    if(row[i]==1 && col[j]==1)ans++;
                }
            }
        }
        return ans;
    }
};