class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1)return 0;
        int mini=INT_MAX;
        for(int i=0;i<=nums.size()-k;i++){
            mini=min(mini,nums[i+k-1]-nums[i]);
        }
        return mini;
    }
};