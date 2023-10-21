class Solution {
public:
    int recur(int index,int k,vector<int>&nums,vector<int>&dp,priority_queue<pair<int,int>>&pq){
        //base case
        if(index>=nums.size())return 0;
        if(index==nums.size()-1){
            pq.push({nums[index],index});
            return dp[index]=nums[index];
        }
        //just to go till the end to backtrack
        int end=recur(index+1,k,nums,dp,pq);
        //to find a particular precalculated dp[index] which has index valid to use
        while(pq.top().second>index+k){
            pq.pop();
        }
        //now that we found such index which is precalculated and is highest with dp value then we check if it's good to add that or just move ahead with this index value bcz probably we get a negative value from max dp previously then why would we add it to current dp and continue without it
        dp[index]=max(nums[index],nums[index]+pq.top().first);
        //now for this index resultant dp also to be pushed in priority queue for calculations for other indexes
        pq.push({dp[index],index});
        return dp[index];
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>dp(nums.size(),INT_MIN);
        int ans=recur(0,k,nums,dp,pq);
        int maxi=INT_MIN;
        for(int i=0;i<dp.size();i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};