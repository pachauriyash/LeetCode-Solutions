class Solution {
public:
    int prime = 1e9+7;
    int recur(int i,int j,string &s,string &t, vector<vector<int>>&dp){
        if(i<j)return 0;
        if(j<0){return 1;}
        if(i<0){return 0;}
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=recur(i-1,j-1,s,t,dp)+recur(i-1,j,s,t,dp);
        }
        else{
            return dp[i][j]=recur(i-1,j,s,t,dp);
        }
    }
    //using lcs code only with modifications
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        //memoriation
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return recur(n-1,m-1,s,t,dp);
        //for tabulation just use +1 indexing and convert
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%prime;
                }
                else{
                     dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};