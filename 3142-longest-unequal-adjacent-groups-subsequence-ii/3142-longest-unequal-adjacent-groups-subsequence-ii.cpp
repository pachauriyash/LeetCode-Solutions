class Solution {
public:
    int hammingDist(string str1, string str2) 
{ 
    int i = 0, count = 0; 
    while (str1[i] != '\0') { 
        if (str1[i] != str2[i]) 
            count++; 
        i++; 
    } 
    return count; 
} 
    // void recur(int index,int prev,vector<int>&groups,vector<int>&ans,vector<int>&temp,vector<vector<bool>>&dp, vector<string>& words){
    //     //base case
    //     if(index==groups.size()){
    //         if(temp.size()>ans.size()){
    //             ans=temp;
    //         }
    //         return;
    //     }
    //     //if(dp[index][prev+1]==true)return;
    //     recur(index+1,prev,groups,ans,temp,dp,words);
    //     if(prev==-1 || (groups[prev]!=groups[index] && words[index].size()==words[prev].size() && hammingDist(words[index],words[prev])==1)){
    //         temp.push_back(index);
    //         recur(index+1,index,groups,ans,temp,dp,words);
    //         temp.pop_back();
    //     }
    //     //dp[index][prev+1]=true;
    // }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
//         vector<int>ans;
//         vector<int>temp;
//         vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
//         recur(0,-1,groups,ans,temp,dp,words);
//         vector<string>ans2;
        
//         for(int i=0;i<ans.size();i++){
//             ans2.push_back(words[ans[i]]);
//         }
//         return ans2;
        int maxi=0;
        int lastindex=0;
        vector<int>dp(groups.size(),1),hash(groups.size());
        for(int i=0;i<groups.size();i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(groups[prev]!=groups[i] && words[i].size()==words[prev].size() && hammingDist(words[i],words[prev])==1 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastindex=i;
            }
        }
       vector<string> lis;
        lis.push_back(words[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            lis.push_back(words[lastindex]);
        }
        reverse(lis.begin(),lis.end());
        // vector<string>ans;
        // for(int i=0;i<lis.size();i++){
        //     ans.push_back(words[lis[i]]);
        // }
        // return ans;
        return lis;
    }
    
};