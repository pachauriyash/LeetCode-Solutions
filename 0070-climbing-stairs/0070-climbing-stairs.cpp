class Solution {
public:
    int recur(int index,vector<int>&dp){
        if(index<0){return 0;}
        if(index==0){return 1;}
        if(dp[index]!=-1){return dp[index];}
        return dp[index]=recur(index-1,dp)+recur(index-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        if(n<=2){return n;}
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};