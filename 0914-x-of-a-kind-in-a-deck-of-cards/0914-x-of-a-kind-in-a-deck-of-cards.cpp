class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int>mp;
        for(int i=0;i<deck.size();i++){
            mp[deck[i]]++;
        }
        int res=0;
        for(auto it:mp){
            res=__gcd(res,it.second);
        }
        return res>1;
    }
};