class Solution {
public:
    int recur(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        if(i==nums1.size() || j==nums2.size()){
            return -1e9;
        }
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        // int take=INT_MIN;
        // for(int k=j;k<nums2.size();k++){
        //     take=max(take,nums1[i]*nums2[k]+recur(i+1,k+1,nums1,nums2,dp));
        // }
        int take=max({nums1[i]*nums2[j],nums1[i]*nums2[j]+recur(i+1,j+1,nums1,nums2,dp),recur(i+1,j,nums1,nums2,dp),recur(i,j+1,nums1,nums2,dp)});
        return dp[i][j]=take;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,INT_MIN));
        return recur(0,0,nums1,nums2,dp);
    }
};