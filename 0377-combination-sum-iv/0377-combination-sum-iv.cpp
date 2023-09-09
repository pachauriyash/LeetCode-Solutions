class Solution {
public:
    int recur(vector<int>& nums,int target,vector<int>&dp){
        if(target==0)return 1;
        if(dp[target]!=-1)return dp[target];
        int count=0;
        
        for(auto& val:nums){
            if(val<=target){
                count+=recur(nums,target-val,dp);
            }
        }
        return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return recur(nums,target,dp);
    }
};