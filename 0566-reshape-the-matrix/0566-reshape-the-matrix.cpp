class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans;
        vector<int> temp;
        int m=mat.size();
        int n=mat[0].size();
        int rr=0;
        int cc=0;
        if(m*n==r*c){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(cc<c){
                        temp.push_back(mat[i][j]);
                        cc++;
                    }
                    else{
                        rr++;
                        cc=0;
                        ans.push_back(temp);
                        temp.clear();
                        temp.push_back(mat[i][j]);
                        cc++;
                    } 
            }
        }
        ans.push_back(temp);
        return ans;
    }
        
    return mat;
    }
    
};