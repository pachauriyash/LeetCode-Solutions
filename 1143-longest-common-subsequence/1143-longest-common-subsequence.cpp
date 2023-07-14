class Solution {
public:
    int recur(int index1,int index2,string &text1, string &text2,vector<vector<int>>&dp){
        if(index1<0 || index2<0){return 0;}
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(text1[index1]==text2[index2]){return 1+recur(index1-1,index2-1,text1,text2,dp);}
        return dp[index1][index2]=max(recur(index1-1,index2,text1,text2,dp),recur(index1,index2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        //memoriztion TC O(N*M) SC O(N*M) + O(N+M)
        // vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        // return recur(text1.length()-1,text2.length()-1,text1,text2,dp);
        //tabulation TC O(N*M) SC O(N*M)
        // vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
        // //if(text1[0]==text2[0]){dp[0][0]=1;}
        // for(int i=1;i<=text1.length();i++){
        //     for(int j=1;j<=text2.length();j++){
        //         if(text1[i-1]==text2[j-1]){dp[i][j]=1+dp[i-1][j-1];}
        //         else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
        //     }
        // }
        // return dp[text1.length()][text2.length()];
        //space optimised
        vector<int>prev(text2.length()+1,0),curr(text2.length()+1,0);
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1]){curr[j]=1+prev[j-1];}
                else{curr[j]=max(prev[j],curr[j-1]);}
            }
            prev=curr;
        }
        return prev[text2.length()];
    }
};