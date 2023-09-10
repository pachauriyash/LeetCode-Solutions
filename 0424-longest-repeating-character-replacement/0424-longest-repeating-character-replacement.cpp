class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;
        int i=0,j=0,largest=0,res=-1;
        while(j<s.size()){
            largest=max(largest,++mp[s[j]]);
            while(j-i+1-largest>k){
                mp[s[i]]--;
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};