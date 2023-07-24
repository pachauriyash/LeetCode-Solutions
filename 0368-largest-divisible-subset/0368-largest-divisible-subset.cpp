class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int lastindex=0;
        vector<int>dp(nums.size(),1),hash(nums.size());
        for(int i=0;i<nums.size();i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastindex=i;
            }
        }
        vector<int>lis;
        lis.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            lis.push_back(nums[lastindex]);
        }
        reverse(lis.begin(),lis.end());
        return lis;
    }
};