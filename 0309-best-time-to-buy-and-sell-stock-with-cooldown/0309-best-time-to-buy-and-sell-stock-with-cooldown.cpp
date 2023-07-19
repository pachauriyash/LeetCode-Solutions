class Solution {
public:
    int recur(int index,int buy,vector<int>&prices,vector<vector<int>>&dp){
        //base case
        if(index>=prices.size())return 0;
        // if(index==prices.size()-1){
        //     if(!buy){
        //         return prices[index];
        //     }
        //     else{
        //         return 0;
        //     }
        // }
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit;
        if(buy){
            profit=max(-prices[index]+recur(index+1,0,prices,dp),recur(index+1,1,prices,dp));
        }
        else{
            profit=max(prices[index]+recur(index+2,1,prices,dp),recur(index+1,0,prices,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        //memoriation TC O(N*2) SC O(N*2)+O(N)
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return recur(0,1,prices,dp);
    }
};