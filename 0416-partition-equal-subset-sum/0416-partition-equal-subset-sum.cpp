class Solution {
public:
    bool recur(int index,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0)return true;
    if(index==0)return arr[0]==target;
    if(dp[index][target]!=-1)return dp[index][target];
    bool nottake=recur(index-1,target,arr,dp);
    bool take=false;
    if(arr[index]<=target)take=recur(index-1,target-arr[index],arr,dp);
    return dp[index][target]=take || nottake;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2!=0)return false;
        int k=sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return recur(n-1,k,nums,dp);
    }
};