class Solution {
public:
    bool isvowel(char c){
        if(c=='a' ||c=='e'||c=='i'||c=='o'||c=='u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int ans=0;
        int count=0;
        while(j<s.size()){
            if(isvowel(s[j]))count++;
            if(j-i+1==k){
                ans=max(ans,count);
                if(isvowel(s[i]))count--;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return ans;
    }
};