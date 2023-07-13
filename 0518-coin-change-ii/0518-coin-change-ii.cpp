class Solution {
public:
    int recur(int index,int target,vector<int>coins,vector<vector<int>>&dp){
        if(index==0){
            if(target%coins[0]==0){return 1;}
            else return 0;
        }
        if(dp[index][target]!=-1)return dp[index][target];
        int notpick=0+recur(index-1,target,coins,dp);
        int pick=0;
        if(coins[index]<=target)pick=recur(index,target-coins[index],coins,dp);
        return dp[index][target]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       return recur(coins.size()-1,amount,coins,dp);
    }
};