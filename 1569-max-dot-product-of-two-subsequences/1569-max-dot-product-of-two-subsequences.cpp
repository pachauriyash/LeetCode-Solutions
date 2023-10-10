class Solution {
public:
    int recur(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        if(i==nums1.size()){
            if(j==0)return INT_MIN;
            return 0;
        }
        //if(mp.find({i,j})!=mp.end())return mp[{i,j}];
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        int nottake=recur(i+1,j,nums1,nums2,dp);
        int take=INT_MIN;
        for(int k=j;k<nums2.size();k++){
            take=max(take,nums1[i]*nums2[k]+recur(i+1,k+1,nums1,nums2,dp));
        }
        //mp.insert({{i,j},max(take,nottake)});
        return dp[i][j]=max(take,nottake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        map<pair<int,int>,int>mp;
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,INT_MIN));
        return recur(0,0,nums1,nums2,dp);
    }
};