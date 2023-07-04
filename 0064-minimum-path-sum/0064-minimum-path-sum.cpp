class Solution {
public:
    int recur(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(row<0 || col<0){return INT_MAX;}
        if(row==0 && col==0){return grid[row][col];}
        if(dp[row][col]!=-1){return dp[row][col];}
        long long up=grid[row][col];
        up+=recur(row-1,col,grid,dp);
        long long left=grid[row][col];
        left+=recur(row,col-1,grid,dp);
        return dp[row][col]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recur(n-1,m-1,grid,dp);
    }
};