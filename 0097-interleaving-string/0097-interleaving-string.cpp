class Solution {
public:
    bool recur(int index1,int index2,int index3,string s1,string s2,string s3,vector<vector<int>>&dp){
        //base
        if(index1==s1.size() && index2==s2.size() && index3==s3.size())return true;
        // if(index1>s1.size()||index2>s2.size()){
        //     return false;
        // }
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(s3[index3]==s1[index1] && s3[index3]==s2[index2]){
            return dp[index1][index2]= recur(index1+1,index2,index3+1,s1,s2,s3,dp) || recur(index1,index2+1,index3+1,s1,s2,s3,dp);
        }
        if(s3[index3]==s1[index1]){
            return dp[index1][index2]= recur(index1+1,index2,index3+1,s1,s2,s3,dp);
        }
        else if(s3[index3]==s2[index2]){
            return dp[index1][index2]= recur(index1,index2+1,index3+1,s1,s2,s3,dp);
        }
        else{
            return dp[index1][index2]=false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        bool ans=false;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        //map<pair<int,int>,string>dp;
       return recur(0,0,0,s1,s2,s3,dp);
       
    }
};