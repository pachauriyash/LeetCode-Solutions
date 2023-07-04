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
        //memoriztion solution TC O(N*M) SC O(2*N*M)
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // return recur(n-1,m-1,grid,dp);
        //tabulation solution
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)dp[0][0]=grid[0][0];
                else{
                    int up=grid[i][j];
                    int left=grid[i][j];
                    if(i>0)up+=dp[i-1][j];
                    else{up=INT_MAX;}
                    if(j>0)left+=dp[i][j-1];
                    else{left=INT_MAX;}
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
        
    }
};