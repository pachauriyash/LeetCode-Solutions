class Solution {
public:
    int recur(int index,int buy,vector<int>&prices,vector<vector<int>>&dp){
        //base case
        if(index==prices.size()-1){
            if(!buy){
                return prices[index];
            }
            else{
                return 0;
            }
        }
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit;
        if(buy){
            profit=max(-prices[index]+recur(index+1,0,prices,dp),recur(index+1,1,prices,dp));
        }
        else{
            profit=max(prices[index]+recur(index+1,1,prices,dp),recur(index+1,0,prices,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        //memoriation TC O(N*2) SC O(N*2)+O(N)
        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return recur(0,1,prices,dp);
        //tabulation TC O(N*2) SC O(N*2)
//         vector<vector<int>>dp(prices.size(),vector<int>(2,0));
//         dp[prices.size()-1][0]=prices[prices.size()-1];
//         dp[prices.size()-1][1]=0;
//         for(int index=prices.size()-2;index>=0;index--){
//             for(int buy=0;buy<=1;buy++){
//                  int profit;
//             if(buy){
//                 profit=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
//             }
//             else{
//                 profit=max(prices[index]+dp[index+1][1],dp[index+1][0]);
//             }
//             dp[index][buy]=profit;
//             }
               
//         }
//         return dp[0][1];
        //greedy
        int maxprofit=0;
        for(int i=1;i<prices.size();i++){
            maxprofit+=max(prices[i]-prices[i-1],0);
        }
        return maxprofit;
    }
}; 