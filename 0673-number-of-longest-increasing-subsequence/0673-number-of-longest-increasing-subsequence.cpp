class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxi=1;
        vector<int>dp(nums.size(),1),count(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    //found longes sequence so the count will be then the prev
                    count[i]=count[prev];
                }
                else if(nums[prev]<nums[i] && 1+dp[prev]==dp[i]){
                    //dound another seq of same length so count will add up
                    count[i]+=count[prev];
                }
            }
            //taking the maximum lis until now
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<dp.size();i++){
            if(dp[i]==maxi)ans+=count[i];
        }
        return ans;
    }
};