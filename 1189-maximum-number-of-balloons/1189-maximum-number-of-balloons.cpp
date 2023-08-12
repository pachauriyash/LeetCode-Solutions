class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        for(int i=0;i<text.size();i++){
            if(text[i]=='b'||text[i]=='a'||text[i]=='l'||text[i]=='o'||text[i]=='n'){if(mp.find(text[i])!=mp.end()){
                mp[text[i]]++;
            }
            else{mp.insert({text[i],1});}}
        }
        int temp=0,temp2=0;
        if(mp['b']==0 || mp['a']==0 || mp['l']<2 || mp['o']<2 || mp['n']==0)return 0;
        temp=min(mp['o'],mp['l'])/2;
        temp=min(mp['b'],min(mp['a'],min(mp['n'],temp)));
        return temp;
    }
};