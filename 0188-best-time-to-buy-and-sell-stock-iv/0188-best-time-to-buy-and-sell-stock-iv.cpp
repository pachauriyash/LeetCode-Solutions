class Solution {
public:
    int recur(int index,int buy,int numsell,vector<int>&prices,vector<vector<vector<int>>>&dp){
        //base case
        if(numsell==0){return 0;}
        if(index==prices.size()-1){
            if(!buy){
                return prices[index];
            }
            else{
                return 0;
            }
        }
        if(dp[index][buy][numsell]!=-1)return dp[index][buy][numsell];
        int profit;
        if(buy){
            profit=max(-prices[index]+recur(index+1,0,numsell,prices,dp),recur(index+1,1,numsell,prices,dp));
        }
        else{
            profit=max(prices[index]+recur(index+1,1,numsell-1,prices,dp),recur(index+1,0,numsell,prices,dp));
        }
        return dp[index][buy][numsell]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         //memoiation TC O(N*2*3) SC O(N*2*3)+O(N)
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return recur(0,1,k,prices,dp);
    }
};