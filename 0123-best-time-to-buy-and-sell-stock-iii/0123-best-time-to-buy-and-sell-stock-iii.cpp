class Solution {
public:
    int recur(int index,int buy,int numsell,vector<int>&prices,vector<vector<vector<int>>>&dp){
        //base case
        if(numsell==2){return 0;}
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
            profit=max(prices[index]+recur(index+1,1,numsell+1,prices,dp),recur(index+1,0,numsell,prices,dp));
        }
        return dp[index][buy][numsell]=profit;
    }
    int maxProfit(vector<int>& prices) {
vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return recur(0,1,0,prices,dp);
    }
};