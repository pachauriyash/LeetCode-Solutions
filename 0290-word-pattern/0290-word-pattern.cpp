class Solution {
public:
    
    bool wordPattern(string pattern, string s) {
        map<char,string> mp;
        int space=0;
            int j=0;
        for(int i=0;i<pattern.size();i++){
            string temp="";
            while(space!=i+1 && j<s.size()){
                if(s[j]==' '){space++;}
                else{temp+=s[j];}
                j++;
            }
            if(temp==""){return false;}
            if(mp.find(pattern[i])==mp.end()){
                for(auto p:mp){
                    if(p.second==temp){return false;}
                }
                mp.insert({pattern[i],temp});
            }
            else{
                if(mp[pattern[i]]!=temp){return false;}
            }
        }
        if(j!=s.size()){return false;}
        return true;
    }
};