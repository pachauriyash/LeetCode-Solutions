class Solution {
public:
    int recur(int index,int largest, int len,int n,int m,int k,vector<vector<vector<int>>>&dp){
        if(index==n){
            if(len==k){
                return 1;
            }
            return 0;
        }
        if(dp[index][largest][len]!=-1)return dp[index][largest][len];
        int ans=0;
        for(int i=1;i<=m;i++){
            if(i>largest){
                ans+=recur(index+1,i,len+1,n,m,k,dp);
            }else{
                ans+=recur(index+1,largest,len,n,m,k,dp);
            }
            ans= ans%1000000007;
        }
        return dp[index][largest][len]=ans;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return recur(0,0,0,n,m,k,dp);
    }
};