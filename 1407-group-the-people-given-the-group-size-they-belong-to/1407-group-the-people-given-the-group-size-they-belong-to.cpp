class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>mp;
        vector<vector<int>>ans;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);

            if(mp[groupSizes[i]].size()==groupSizes[i]){
                ans.push_back(mp[groupSizes[i]]);
                mp.erase(groupSizes[i]);
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};