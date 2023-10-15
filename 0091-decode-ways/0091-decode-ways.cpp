class Solution {
public:
    int recur(int index,string s,vector<int>&dp){
        //base case
        if(index==s.size())return 1;
        if(dp[index]!=-1)return dp[index];
        if(s[index]=='0')return 0;
        int one=recur(index+1,s,dp);
        int two=0;
        if(index!=s.size()-1){
            int temp=stoi(s.substr(index,2));
            if(temp<=26 && temp>=10){
                two=recur(index+2,s,dp);
            }
        }
        return dp[index]=one+two;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        return recur(0,s,dp);
    }
};