class Solution {
public:
    int recur(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(row==matrix.size()-1){return matrix[row][col];}
        if(dp[row][col]!=INT_MAX){return dp[row][col];}
        int down=matrix[row][col]+recur(row+1,col,matrix,dp);
        int leftdiag,rightdiag;
        if(col>0){leftdiag=matrix[row][col]+recur(row+1,col-1,matrix,dp);}
        else{leftdiag=INT_MAX;}
        if(col<matrix.size()-1){rightdiag=matrix[row][col]+recur(row+1,col+1,matrix,dp);}
        else{rightdiag=INT_MAX;}
        return dp[row][col]=min(down,min(leftdiag,rightdiag));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),INT_MAX));
            ans=min(ans,recur(0,i,matrix,dp));
        }
        return ans;
    }
};