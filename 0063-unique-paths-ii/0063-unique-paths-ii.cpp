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
        vector<vector<int>> dphash(m,vector<int>(n,-1));
        return recur(m,n,0,0,dphash,obstacleGrid);
    }
};