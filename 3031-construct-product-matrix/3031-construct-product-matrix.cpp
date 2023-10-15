class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>vt(grid.size(),vector<int>(grid[0].size(),1));
        int n=grid.size();
        int m=grid[0].size();
        unsigned long long mul=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vt[i][j]=mul;
                mul=(mul*grid[i][j])%12345;
            }
        }
        mul=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                vt[i][j]=(vt[i][j]*mul)%12345;
                mul=(mul*grid[i][j])%12345;
            }
        }
        return vt;
    }
};