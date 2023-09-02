class Solution {
public:
    int recur(int index,string &s,set<string>&st,vector<int>&dp){
        if(index>=s.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int skip=1+recur(index+1,s,st,dp);
        //not skip and find the match strings
        int notskip=INT_MAX;
        for(int i=1;i<=s.size()-index;i++){
            //substrings of different sizes starting from this index
            string temp=s.substr(index,i);
            if(st.find(temp)!=st.end()){notskip=min(notskip,recur(i+index,s,st,dp));}
        }
        return dp[index]=min(notskip,skip);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string>st;
        vector<int>dp(s.size(),-1);
        for(auto it:dictionary)st.insert(it);
        return recur(0,s,st,dp);
    }
};