class Solution {
public:
    int recur(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j)return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int index=i;index<=j;index++){
            int cost=cuts[j+1]-cuts[i-1]+recur(i,index-1,cuts,dp)+recur(index+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return recur(1,cuts.size()-2,cuts,dp);
    }
};