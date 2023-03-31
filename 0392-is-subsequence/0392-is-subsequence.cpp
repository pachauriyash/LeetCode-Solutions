class Solution {
public:
   
    bool isSubsequence(string s, string t) {
        int prev=-1;
        if(t.size()<s.size()){return false;}
        for(int i=0;i<s.size();i++){
            if(s.size()-i>t.size()-prev-1){return false;}
            for(int j=prev+1;j<t.size();j++){
                if(s[i]==t[j]){prev=j;break;}
                if(j==t.size()-1){return false;}
            }
        }
        return true;
    }
};