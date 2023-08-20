class Solution {
public:
    int recur(int index,vector<int>& costs,vector<int>& days,vector<int>&dp){
        //base case
        if(index>=days.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int oneday=0,sevenday=0,thirtyday=0;
        int sevenindex=upper_bound(days.begin()+index+1,days.end(),days[index]+7-1)-days.begin();
        int thirtyindex=upper_bound(days.begin()+index+1,days.end(),days[index]+30-1)-days.begin();
        //cout<<sevenindex<<" "<<thirtyindex<<" ";
        oneday=costs[0]+recur(index+1,costs,days,dp);
        sevenday=costs[1]+recur(sevenindex,costs,days,dp);
        thirtyday=costs[2]+recur(thirtyindex,costs,days,dp);
        
        return dp[index]=min(oneday,min(sevenday,thirtyday));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(),days.end());
        vector<int>dp(365,-1);
        return recur(0,costs,days,dp);
    }
};