class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            map<char,int>mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                if(j-i+1>2){
                    int mostfreq=0,least=j-i+1;
                    for(auto it:mp){
                        mostfreq=max(mostfreq,it.second);
                        least=min(least,it.second);
                    }
                    sum+=mostfreq-least;
                }
            }
        }
        return sum;
    }
};