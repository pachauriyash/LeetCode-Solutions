class Solution {
public:
    //normal recursive solution without dp or partition but it will tle very soon
    int recur(vector<int>& nums){
        int maxi=INT_MIN;
        if(nums.size()==0){return 0;}
        for(int i=0;i<nums.size();i++){
            int coins=0;
            if(i==0 && i==nums.size()-1){
                coins=nums[i];
            }
            else if(i==0 && i+1!=nums.size()){
                coins=nums[i]*nums[i+1];
            }
            else if(i!=0 && i+1==nums.size()){
                coins=nums[i-1]*nums[i];
            }
            else{
                coins=nums[i-1]*nums[i]*nums[i+1];
            }
            int val=nums[i];
            nums.erase(nums.begin()+i);
            coins+=recur(nums);
            nums.insert(nums.begin()+i,val);
            maxi=max(maxi,coins);
        }
        return maxi;
    }
    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        int maxi=INT_MIN;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int index=i;index<=j;index++){
            int cost=nums[i-1]*nums[index]*nums[j+1]+f(i,index-1,nums,dp)+f(index+1,j,nums,dp);
            maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,nums,dp);
        return recur(nums);
    }
};