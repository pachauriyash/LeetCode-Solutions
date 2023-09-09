class Solution {
public:
    int fun(string s){
        map<char,int>mp;
        int i=0,j=0;
        int count=0;
        while(j<s.length()){
            mp[s[j]]++;
            while(i<=j && mp.size()>=3){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        return s.size()*(s.size()+1)/2 -fun(s);
    }
};