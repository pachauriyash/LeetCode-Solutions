class Solution {
public:
int recur(int index,int steps,int endpos,int k,vector<vector<int>>&dp){
        //base case
        if(steps==0){
            if(index==endpos)return 1;
            else return 0;
        }
        if(dp[index+k][steps]!=-1)return dp[index+k][steps];
        int left=0,right=0;
        left=recur(index-1,steps-1,endpos,k,dp)%1000000007;
        right=recur(index+1,steps-1,endpos,k,dp)%1000000007;
        
        return dp[index+k][steps]=(left+right)%1000000007;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(2*k+1,vector<int>(k+1,-1));
        return recur(0,k,endPos-startPos,k,dp);
    }
};