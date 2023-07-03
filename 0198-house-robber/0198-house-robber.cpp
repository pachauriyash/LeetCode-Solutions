class Solution {
public:
    int recur(int index,vector<int> &nums,vector<int>&dp){
    if(index==0)return nums[index];
    if(index<0)return 0;
    if(dp[index]!=-1)return dp[index];
    int pick=nums[index]+recur(index-2,nums,dp);
    int notpick=recur(index-1,nums,dp);
    return dp[index]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return recur(nums.size()-1,nums,dp);
        //this solution is same as Maximum sum of non-adjacent elements in striver dp sheet and here used direct space optimised solution but can be done with memorization first
    //     int curr;
    // int prev2=nums[0];
    // if(nums.size()==1){return prev2;}
    // int prev=max(nums[1],prev2);
    // for(int i=2;i<nums.size();i++){
    //     curr=max(nums[i]+prev2,prev);
    //     prev2=prev;
    //     prev=curr;
    // }
    // return prev;
    }
};