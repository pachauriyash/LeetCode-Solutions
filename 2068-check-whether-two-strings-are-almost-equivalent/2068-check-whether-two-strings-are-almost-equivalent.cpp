class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char,int>mp1,mp2;
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
        }
        for(int i=0;i<word2.size();i++){
            mp2[word2[i]]++;
        }
        //if(mp1.size()!=mp2.size())return false;
        for(auto it:mp1){
            if(mp2.find(it.first)==mp2.end()){
                if(it.second>3)return false;
            }
            else{
                if(abs(it.second-mp2[it.first])>3)return false;
            }
        }
        for(auto it:mp2){
            if(mp1.find(it.first)==mp1.end()){
                if(it.second>3)return false;
            }
            else{
                if(abs(it.second-mp1[it.first])>3)return false;
            }
        }
        return true;
    }
};