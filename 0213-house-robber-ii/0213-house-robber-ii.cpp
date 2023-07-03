class Solution {
public:
    int recur(int index,vector<int> &nums,vector<int>&dp){
        if(index==0){return nums[index];
        }
        if(index<0)return 0;
        if(dp[index]!=-1)return dp[index];
        
        int pick=nums[index]+recur(index-2,nums,dp);
        int notpick=recur(index-1,nums,dp);
        return dp[index]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        vector<int> dp(nums.size()-1,-1),dp2(nums.size()-1,-1); 
        vector<int>temp1,temp2;
        temp1.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(i!=nums.size()-1)temp1.push_back(nums[i]);
            temp2.push_back(nums[i]);
        }
        return max(recur(nums.size()-2,temp1,dp),recur(nums.size()-2,temp2,dp2));
    }
};