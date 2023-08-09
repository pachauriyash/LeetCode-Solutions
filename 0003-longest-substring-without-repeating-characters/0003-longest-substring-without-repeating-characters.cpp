class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            map<char,int>mp;
            int temp=0;
            for(int j=i;j<s.length();j++){
                if(mp.find(s[j])==mp.end()){
                    mp[s[j]]++;
                    temp++;
                }
                else{
                    ans=max(ans,temp);
                    break;
                }
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};