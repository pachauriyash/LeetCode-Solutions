class Solution {
public:
    int countPoints(string rings) {
        map<char,unordered_set<char>>mp;
        for(int i=0;i<rings.size()-1;i+=2){
            // if(mp.find(rings[i+1])!=mp.end()){
            //     mp[rings[i+1]].insert(rings[i]);
            // }
            // else{
            //     mp.insert({rings[i+1],{rings[i]}});
            // }
            mp[rings[i+1]].insert(rings[i]);
        }
        int count=0;
        for(auto it:mp){
            //cout<<it.first<<" ";
            if(it.second.size()==3){count++;}
        }
        return count;
    }
};