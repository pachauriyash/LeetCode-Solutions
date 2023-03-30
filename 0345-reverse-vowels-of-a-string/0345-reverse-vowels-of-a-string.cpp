class Solution {
public:
    bool isvowel(char c){
        if(c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        vector<char> v;
        for(int i=0;i<s.size();i++){
            if(isvowel(char(s[i]))){v.push_back(s[i]);}
        }
        int j=v.size()-1;
        for(int i=0;i<s.size();i++){
            if(isvowel(char(s[i]))){
                s[i]=v[j];
                j--;
            }
        }
        return s;
    }
};