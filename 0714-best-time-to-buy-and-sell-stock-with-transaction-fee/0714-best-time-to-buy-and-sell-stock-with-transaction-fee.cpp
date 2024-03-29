class Solution {
public:
    int recur(int index,int buy,vector<int>&prices,vector<vector<int>>&dp,int &fee){
        //base case
        if(index==prices.size()-1){
            if(!buy){
                return prices[index]-fee;
            }
            else{
                return 0;
            }
        }
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit;
        if(buy){
            profit=max(-prices[index]+recur(index+1,0,prices,dp,fee),recur(index+1,1,prices,dp,fee));
        }
        else{
            profit=max(prices[index]+recur(index+1,1,prices,dp,fee)-fee,recur(index+1,0,prices,dp,fee));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        //memoriation TC O(N*2) SC O(N*2)+O(N)
        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return recur(0,1,prices,dp,fee);
        //tabulation TC O(N*2) SC O(N*2)
        vector<vector<int>>dp(prices.size(),vector<int>(2,0));
        dp[prices.size()-1][0]=prices[prices.size()-1]-fee;
        dp[prices.size()-1][1]=0;
        for(int index=prices.size()-2;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                 int profit;
            if(buy){
                profit=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
            }
            else{
                profit=max(prices[index]-fee+dp[index+1][1],dp[index+1][0]);
            }
            dp[index][buy]=profit;
            }
               
        }
        return dp[0][1];
    }
};