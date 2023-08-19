class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int> > pq;
        sort(nums.begin(),nums.end());
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){count++;}
            else{
                pq.push({count,nums[i-1]});
                count=1;
            }
        }
        pq.push({count,nums[nums.size()-1]});
        vector<int>ans;
        for(int i=0;i<k;i++){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};