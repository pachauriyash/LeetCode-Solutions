class Solution {
public:
    bool recur(int i,int j, string &pattern, string &s,vector<vector<int>>&dp){
        if(i<0 && j<0)return true;
        if(i<0 && j>=0)return false;
        if(i>=0 && j<0){
            for(int ii=0;ii<=i;ii++){
                if(pattern[ii]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(pattern[i]==s[j] || pattern[i]=='?')return recur(i-1,j-1,pattern,s,dp);
        if(pattern[i]=='*')return dp[i][j]=(recur(i-1,j,pattern,s,dp) || recur(i,j-1,pattern,s,dp));
        return false;
    }
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recur(n-1,m-1,p,s,dp);
    }
};