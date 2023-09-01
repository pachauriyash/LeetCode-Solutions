class Solution {
public:
    long long recur(vector<int>&nums,int index,int m,vector<vector<int>>&dp){
    //base case when m==1
        //you exhausted all the partitions and no element left or you reached end
        if(m==0 && index==nums.size())return 0;
        //basically you exhausted all the partitions and still there are elements left
        if(m==0)return 1e9;
        if(index==nums.size())return 1e9;
    if(dp[index][m]!=-1)return dp[index][m];
    long long sum=0;
    long long ans=INT_MAX,maxi=INT_MIN;
    for(int i=index;i<nums.size();i++){
        sum+=nums[i];
       maxi=max(sum,recur(nums,i+1,m-1,dp));
        ans=min(maxi,ans);
    }
    return dp[index][m]=ans;
}
    //binary search solution
    int countstud(vector<int>& arr, int n,int limit){
    int count=0,temp=0;  
    for(int i=0;i<n;i++){
        temp+=arr[i];
        if(temp>limit){
            count++;
            temp=arr[i];
        }
    }
    return ++count;
}
    int splitArray(vector<int>& nums, int k) {
        // vector<vector<int>>dp(nums.size()+1,vector<int>(k+1,-1));
        // if(k>nums.size())return -1;
        // return recur(nums,0,k,dp);
        
        //binary search
        int n=nums.size();
        if(k>n)return -1;
    int low=INT_MIN,high=INT_MAX;
    for(int i=0;i<n;i++)low=max(low,nums[i]);
    while(low<=high){
        int mid=low+(high-low)/2;
        if(countstud(nums,n,mid)>k){
            low=mid+1;
        }
        else{high=mid-1;}
    }
    return low;
    }
};