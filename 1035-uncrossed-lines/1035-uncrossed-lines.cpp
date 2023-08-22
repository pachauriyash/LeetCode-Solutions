class Solution {
public:
//     int recur(vector<int>& nums1, vector<int>& nums2,int index1,int index2,vector<vector<int>>&dp){
//         //base case
//         if(index1>=nums1.size() || index2>=nums2.size()){return 0;}
//         if(dp[index1][index2]!=-1)return dp[index1][index2];
        
//         int index=index2;
//         while(index<nums2.size() && nums2[index]!=nums1[index1]){index++;}
//         int take=0;
//         if(index!=nums2.size() && nums2[index]==nums1[index1]){
//             //cout<<index1<<" "<<index2<<" "<<"balee";
//             take=1+recur(nums1,nums2,index1+1,index+1,dp);
//         }
//         int nottake=recur(nums1,nums2,index1+1,index2,dp);
//         return dp[index1][index2]=max(take,nottake);
//     }
    int recur(vector<int>& nums1, vector<int>& nums2,int index1,int index2,vector<vector<int>>&dp){
        //base case
        if(index1>=nums1.size() || index2>=nums2.size()){return 0;}
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        
        
        if(nums2[index2]!=nums1[index1]){
            return dp[index1][index2]= max(recur(nums1,nums2,index1+1,index2,dp),recur(nums1,nums2,index1,index2+1,dp));
        }
        else{
             return dp[index1][index2]=1+recur(nums1,nums2,index1+1,index2+1,dp);
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {   
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        return recur(nums1,nums2,0,0,dp);
    }
};