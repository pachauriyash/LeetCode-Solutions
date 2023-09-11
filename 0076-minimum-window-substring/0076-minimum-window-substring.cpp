class Solution {
public:
    bool isvalid(map<char,int>&mp1,map<char,int>&mp2){
        for(auto it:mp2){
            if(mp1[it.first]<it.second)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char,int>mp1,mp2;
        for(auto it:t){
            mp2[it]++;
        }
        int n=t.size();
        int i=0,j=0;
        int ans=INT_MAX;
        pair<int,int>index={0,-1};
        while(j<s.size()){
            if(mp2.find(s[j])!=mp2.end()){
                mp1[s[j]]++;
            }
            while(mp1.size()==mp2.size() && isvalid(mp1,mp2)){
                if(j-i+1<ans){
                    ans=j-i+1;
                    index={i,j};
                    //answ=s.substr(i,j-i+1);
                    if(ans==n)return s.substr(i,j-i+1);
                }
                if(mp1.find(s[i])!=mp1.end()){
                    mp1[s[i]]--;
                    if(mp1[s[i]]==0)mp1.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return s.substr(index.first,index.second-index.first+1);
    }
};