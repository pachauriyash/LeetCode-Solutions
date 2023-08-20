class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int>mp;
        int size=sentence.size();
        if(size<26)return false;
        for(int i=0;i<size;i++){
            mp[sentence[i]]++;
        }
        return mp.size()==26;
    }
};