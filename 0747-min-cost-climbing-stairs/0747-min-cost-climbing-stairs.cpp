class Solution {
public:
    int recur(int index,vector<int>&cost,vector<int>&dp){
        if(index>=cost.size())return 0;
        if(dp[index]!=-1)return dp[index];
        return dp[index]=cost[index]+min(recur(index+1,cost,dp),recur(index+2,cost,dp));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int ans=INT_MAX;
        for(int i=0;i<2;i++){
            vector<int>dp(cost.size(),-1);
            ans=min(ans,recur(i,cost,dp));
        }
        return ans;
    }
};