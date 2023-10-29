class Solution {
public:

    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<long long>dp(nums.size(),0);
        dp[0]=max(0,k-nums[0]);
        dp[1]=max(0,k-nums[1]);
        dp[2]=max(0,k-nums[2]);
        for(int i=3;i<nums.size();i++){
            dp[i]=max(0,k-nums[i])+min({dp[i-1],dp[i-2],dp[i-3]});
        }
        int n=nums.size()-1;
        return min({dp[n],dp[n-1],dp[n-2]});
    }
};