class Solution {
public:
    int recur(int index,int prev,vector<int>&nums, vector<vector<int>>&dp){
        if(index==nums.size())return 0;

            if(dp[index][prev+1]!=-1)return dp[index][prev+1];

        
        int len=recur(index+1,prev,nums,dp);
        if(prev==-1 || nums[index]>nums[prev]){
            len=max(len,1+recur(index+1,index,nums,dp));
        }
        return dp[index][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        //memoriation solution but this will also cause TLE bcz constraints are big
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        // return recur(0,-1,nums,dp);
        //tabultaion
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int index=nums.size()-1;index>=0;index--){
            for(int prev=index-1;prev>=-1;prev--){
                int len=dp[index+1][prev+1];
                if(prev==-1 || nums[index]>nums[prev]){
                    len=max(len,1+dp[index+1][index+1]);
                }
                dp[index][prev+1]=len;
            }
        }
        return dp[0][-1+1];
    }
};