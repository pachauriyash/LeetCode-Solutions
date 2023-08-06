class Solution {
public:
    bool static comp(pair<int,int>p1,pair<int,int>p2){
        if(p1.second<p2.second){return true;}
        else if(p1.second==p2.second){
            if(p1.first>p2.first){return true;}
        }
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
         vector<pair<int,int> > vec;
         for(auto pr:mp)
         {
             vec.push_back(pr);
         }
         sort(vec.begin(),vec.end(),comp);
        vector<int>ans;
        for(auto it:vec){
            int times=it.second;
            while(times>0){
                ans.push_back(it.first);
                times--;
            }

        }
        return ans;
    }
};