class Solution {
public:
    int recur(int index1,int index2,string &text1, string &text2,vector<vector<int>>&dp){
        if(index1<0 || index2<0){return 0;}
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(text1[index1]==text2[index2]){return 1+recur(index1-1,index2-1,text1,text2,dp);}
        return dp[index1][index2]=max(recur(index1-1,index2,text1,text2,dp),recur(index1,index2-1,text1,text2,dp));
    }
    
    int minInsertions(string text1) {
        //we'll use longest palindrominc subsequence code here and the logic is expalined in notes and video
        string text2="";
        for(int i=text1.length()-1;i>=0;i--){
            text2+=text1[i];
        }
         //memoiation TC O(N*N)+O(N) SC O(N*N)+O(2N)
        //  vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        // return text1.length()-recur(text1.length()-1,text2.length()-1,text1,text2,dp);
        //tabulation TC O(N*N)+O(N) SC O(N*N)
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1]){dp[i][j]=1+dp[i-1][j-1];}
                else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
            }
        }
        return text1.length()-dp[text1.length()][text2.length()];
    }
};