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
        //memorization TC O(N*amount) SC O(N*amount)+O(N)
       //  vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       // return recur(coins.size()-1,amount,coins,dp);
        //tabulation TC O(N*amount) SC O(N*amount)
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++){
           if(target%coins[0]==0)dp[0][target]=1;
            else dp[0][target]=0;
        }
        for(int index=1;index<coins.size();index++){
            for(int target=0;target<=amount;target++){
                int notpick=0+dp[index-1][target];
                int pick=0;
                if(coins[index]<=target)pick=dp[index][target-coins[index]];
                dp[index][target]=pick+notpick;
            }
        }
         return dp[coins.size()-1][amount];
    }
};