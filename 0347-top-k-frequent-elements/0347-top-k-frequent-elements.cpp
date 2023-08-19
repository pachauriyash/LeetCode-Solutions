class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int> > pq;
        map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
       for(auto it:mp){
           pq.push({it.second,it.first});
       }
        vector<int>ans;
        for(int i=0;i<k;i++){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};