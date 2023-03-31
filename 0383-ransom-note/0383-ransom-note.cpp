class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        /*int i=0;
        int j=0;
        if(ransomNote.size()>magazine.size()){return false;}
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        while(i<ransomNote.size() && j<magazine.size()){
            if(ransomNote[i]!=magazine[j]){return false;}
            i++;
            j++;
        }
        return true; */
        int prev=-1;
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        string s=ransomNote;
        string t=magazine;
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