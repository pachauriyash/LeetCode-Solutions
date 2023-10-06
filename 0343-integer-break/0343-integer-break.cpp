class Solution {
public:
    int recur(int n,vector<int>&dp){
        //base case
        if(n==1 || n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int maxi=0;
        for(int i=1;i<=n;i++){
            int calc=i*recur(n-i,dp);
            maxi=max(maxi,calc);
        }
        return dp[n]=maxi;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        if(n==2)return 1;
        if(n==3)return 2;
        return recur(n,dp);
    }
};