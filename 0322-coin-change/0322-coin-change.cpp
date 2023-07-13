class Solution {
public:
    int recur(int index,int target,vector<int>coins,vector<vector<int>>&dp){
        if(index==0){
            if(target%coins[0]==0){return target/coins[0];}
            else return 1e9;
        }
        if(dp[index][target]!=-1)return dp[index][target];
        int notpick=0+recur(index-1,target,coins,dp);
        int pick=INT_MAX;
        if(coins[index]<=target)pick=1+recur(index,target-coins[index],coins,dp);
        return dp[index][target]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        //memoriation but don't know why TLE though TC O(N*amount) SC O(N*amount)+O(N)
        // vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        // int ans= recur(coins.size()-1,amount,coins,dp);
        // if(ans>=1e9){return -1;}
        // return ans;
        //tabulation TC O(N*amount) SC O(N*amount)
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++){
           if(target%coins[0]==0)dp[0][target]=target/coins[0];
            else dp[0][target]=1e9;
        }
        for(int index=1;index<coins.size();index++){
            for(int target=0;target<=amount;target++){
                int notpick=0+dp[index-1][target];
                int pick=INT_MAX;
                if(coins[index]<=target)pick=1+dp[index][target-coins[index]];
                dp[index][target]=min(pick,notpick);
            }
        }
        int ans=dp[coins.size()-1][amount];
        if(ans>=1e9){return -1;}
        return ans;
    }
};