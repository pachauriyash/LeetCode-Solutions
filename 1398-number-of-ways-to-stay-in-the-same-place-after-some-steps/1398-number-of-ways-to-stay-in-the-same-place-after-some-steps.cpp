class Solution {
public:
    #define mod 1000000007
    int recur(int index,int steps,int &arrlen,vector<vector<int>>&dp){
        //base case
        if(steps==0){
            if(index==0)return 1;
            else return 0;
        }
        if(index>steps)return 0;
        if(dp[index][steps]!=-1)return dp[index][steps];
        int left=0,right=0,stay=0;
        if(index!=0)left=recur(index-1,steps-1,arrlen,dp)%mod;
        if(index!=arrlen-1)right=recur(index+1,steps-1,arrlen,dp)%mod;
        stay=recur(index,steps-1,arrlen,dp)%mod;
        return dp[index][steps]=((left+right)%mod+stay)%mod;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>>dp(steps/2+1,vector<int>(steps+1,-1));
        return recur(0,steps,arrLen,dp);
    }
};