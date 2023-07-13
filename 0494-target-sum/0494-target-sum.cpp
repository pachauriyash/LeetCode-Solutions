class Solution {
public:
    long long recur(int index,int sum,vector<int>&arr,vector<vector<int>>&dp){
	//taking into consideration of zeroes as well
    // if(sum==0)return 1;
	if(index==0){
        if(sum==0 && arr[0]==0){return 2;}
        if(sum==0 || arr[0]==sum){return 1;}
		return 0;
	}
	if(dp[index][sum]!=-1)return dp[index][sum];
	long long nottake=recur(index-1,sum,arr,dp);
	long long take=0;
	if(arr[index]<=sum)take=recur(index-1,sum-arr[index],arr,dp);
	return dp[index][sum]=(take+nottake)%1000000007;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
    for(int i=0;i<n;i++){totalsum+=arr[i];}
    if(totalsum-d<0) return 0;
    if((totalsum-d)%2==1) return 0;
    
    int s2 = (totalsum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return recur(n-1,s2,arr,dp);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
};