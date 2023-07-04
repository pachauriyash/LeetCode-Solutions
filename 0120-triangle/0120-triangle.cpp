class Solution {
public:
    int recur(int row,int col,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(row==triangle.size()-1){return triangle[row][col];}
        if(dp[row][col]!=-1){return dp[row][col];}
        int down=triangle[row][col]+recur(row+1,col,triangle,dp);
        int diag=triangle[row][col]+recur(row+1,col+1,triangle,dp);
        return dp[row][col]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        //return recur(0,0,triangle,dp);
        int n=triangle.size();
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];
    }
};