class Solution {
public:
    int recur(vector<int>&nums,int index,vector<int>&dp){
        //base case
        if(index==nums.size()-1){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        int ans=INT_MAX-1;
        for(int i=1;i<=nums[index];i++){
            if(index+i>nums.size()-1)break;
            ans=min(ans,recur(nums,index+i,dp));
        }
        //if(index==1)cout<<ans<<" ";
        return dp[index]=1+ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return recur(nums,0,dp);
    }
};