class Solution {
public:
    int recur(int n,vector<int>&perf,vector<int>&dp){
        //base case
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int temp=1e9;
        for(auto it:perf){
            if(it<=n){
                temp=min(temp,1+recur(n-it,perf,dp));
            }
        }
        return dp[n]=temp;
    }
    int numSquares(int n) {
        vector<int>perf;
         vector<int>dp(n+1,-1);
        for(int i=1;i<=n;i++){
            int t=sqrt(i);
            if(t*t==i){perf.push_back(i);}
        }
        return recur(n,perf,dp);
    }
};