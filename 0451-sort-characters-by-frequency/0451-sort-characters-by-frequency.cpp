class Solution {
public:
    static bool comp(pair<int,char>p1,pair<int,char>p2){
        return p1.first>p2.first;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++)mp[s[i]]++;
        vector<pair<int,char>>vec;
        for(auto it:mp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end(),comp);
        string ans="";
        for(int i=0;i<vec.size();i++){
            int count=vec[i].first;
            while(count>0){
                ans+=vec[i].second;
                count--;
            }
        }
        return ans;
    }
};