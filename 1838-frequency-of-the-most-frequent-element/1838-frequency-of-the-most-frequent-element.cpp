class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

    long long sum=0;
    int ans=0;
    int i=0;
    sort(begin(nums), end(nums));
    for (int j = 0; j<nums.size(); j++) {
        sum+=nums[j];
        if((long long)nums[j]*(j-i+1)-sum>k){sum-=nums[i];i++;}
        ans=max(ans,j-i+1);
    }
    return ans;
    }
};