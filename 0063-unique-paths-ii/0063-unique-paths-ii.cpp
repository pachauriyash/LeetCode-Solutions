class Solution {
public:
    int recur(int m, int n, int row,int col,vector<vector<int>>&dphash,vector<vector<int>>& obstacleGrid){
        if(row>=m || col>=n){return 0;}
        if(row==m-1 && col==n-1){return 1;}
        if(obstacleGrid[row][col]==1){dphash[row][col]=0;return 0;}
        if(dphash[row][col]!=-1){
            return dphash[row][col];
        }
        return dphash[row][col]= recur(m,n,row+1,col,dphash,obstacleGrid) +recur(m,n,row,col+1,dphash,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid[0].size();
        int m=obstacleGrid.size();
        if(obstacleGrid[m-1][n-1]==1){return 0;}
        //vector<vector<int>> dphash(m,vector<int>(n,-1));
        // return recur(m,n,0,0,dphash,obstacleGrid);
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0 && obstacleGrid[i][j]!=1)dp[i][j]=1;
                else{
                    int up=0,left=0;
                    //because in my memoriation i used from 0,0 to m-1,n-1 so it was down and right
                    if(i>0)up=dp[i-1][j];
                    if(j>0)left=dp[i][j-1];
                    dp[i][j]=left+up;
                    if(obstacleGrid[i][j]==1)dp[i][j]=0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};