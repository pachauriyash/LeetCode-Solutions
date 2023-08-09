class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<=nums.size()-2;i++){
            if(mp.find(nums[i]+nums[i+1])!=mp.end())return true;
            else{
                mp[nums[i]+nums[i+1]]++;
            }
        }
        return false;
    }
};