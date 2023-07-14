class Solution {
public:
    int recur(int index1,int index2,string &text1, string &text2,vector<vector<int>>&dp){
        if(index1<0 || index2<0){return 0;}
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(text1[index1]==text2[index2]){return 1+recur(index1-1,index2-1,text1,text2,dp);}
        return dp[index1][index2]=max(recur(index1-1,index2,text1,text2,dp),recur(index1,index2-1,text1,text2,dp));
    }
    int longestPalindromeSubseq(string text1) {
        string text2="";
        for(int i=text1.length()-1;i>=0;i--){
            text2+=text1[i];
        }
         vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        return recur(text1.length()-1,text2.length()-1,text1,text2,dp);
    }
};