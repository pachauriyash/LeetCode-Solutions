class Solution {
public:
    //simply this can be done using recursion but you get tle so to solve it using a dp hash table
    int recur(int m, int n, int row,int col,vector<vector<int>>&dphash){
        if(row>=m || col>=n){return 0;}
        if(row==m-1 && col==n-1){return 1;}
        if(dphash[row][col]!=-1){
            return dphash[row][col];
        }
        return dphash[row][col]= recur(m,n,row+1,col,dphash) +recur(m,n,row,col+1,dphash);
    }
    int uniquePaths(int m, int n) {
/*  this was optimising recursion to use dp memorization TC O(N*M) SC O(2*N*M)
        vector<vector<int>> dphash(m,vector<int>(n,-1));
        return recur(m,n,0,0,dphash);
        */
        //now the crazy apprach it is using maths and permutation and combination
        //so we know to reach the bottom we have to go m-1 times down and n-1 times right and total steps to go will be m+n-2 now take example of 2X3 so you have 3 steps to take out of which 1 should be down and 2 should be right so you have to fill three boxes in such a manner
        // int down=m-1;
        // int right=n-1;
        // int total=down+right;
        // double result=1;
        // for(int i=1;i<=down;i++){
        //     result=result*(total-down+i)/i;
        // }
        // return (int)result;
        
        //following up this question in dp series previously in arrays and the best method is above maths approach 
        //tabulation method TC O(N*M) SC O(N*M)
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0)dp[i][j]=1;
                else{
                    int up=0,left=0;
                    //because in my memoriation i used from 0,0 to m-1,n-1 so it was down and right
                    if(i>0)up=dp[i-1][j];
                    if(j>0)left=dp[i][j-1];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};