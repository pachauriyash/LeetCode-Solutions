class Solution {
public:
    void recur(int index,string s,map<string,bool>&mp,vector<int>&dp,bool &ans){
        //base case
        if(index==s.size()){
            // for(auto it:mp){
            //     if(it.second==false)return false;
            // }
            ans=true;
            return;
        }
        if(dp[index]!=-1)return;
        string temp="";
        //bool ans=false;
        //ans=ans || recur(index+1,s,mp);
        for(int i=index;i<s.size();i++){
            temp+=s[i];
            if(mp.find(temp)!=mp.end()){
                mp[temp]=true;
                recur(i+1,s,mp,dp,ans);
                mp[temp]=false;
            }
        }
        dp[index]=1;
        return;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool>mp;
        bool ans=false;
        vector<int>dp(s.size()+1,-1);
        for(auto it:wordDict){
            mp.insert({it,false});
        }
        recur(0,s,mp,dp,ans);
        return ans;
    }
};