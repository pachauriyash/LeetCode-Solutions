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
        //memorization TC O(N*N) SC O(N*N)+O(N)
        // int ans=INT_MAX;
        // for(int i=0;i<matrix.size();i++){
        //     vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),INT_MAX));
        //     ans=min(ans,recur(0,i,matrix,dp));
        // }
        // return ans;
        
        //now tabulation but my memorization was from 0,0 to bottom so if from that i would have to make tabulation then base cases will be be bottom row but here i'm going from up to down as in striver video
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int j=0;j<n;j++)dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int down=matrix[i][j]+dp[i-1][j];
                int leftdiag=INT_MAX;
                int rightdiag=INT_MAX;
                if(j>0){leftdiag=matrix[i][j]+dp[i-1][j-1];}
                if(j<n-1){rightdiag=matrix[i][j]+dp[i-1][j+1];}
                dp[i][j]=min(down,min(leftdiag,rightdiag));
            }
        }
        int ans=dp[n-1][0];
        for(int j=1;j<n;j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};