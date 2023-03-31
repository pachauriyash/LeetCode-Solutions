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
        if(magazine.size()<ransomNote.size()){return false;}
        for(int i=0;i<ransomNote.size();i++){
            if(ransomNote.size()-i>magazine.size()-prev-1){return false;}
            for(int j=prev+1;j<magazine.size();j++){
                if(ransomNote[i]==magazine[j]){prev=j;break;}
                if(j==magazine.size()-1){return false;}
            }
        }
        return true;
    }
};