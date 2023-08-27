class Solution {
public:
//     
//     bool isthere(vector<int>& arr, int k){
//         vector<vector<int>>dp(arr.size(),vector<int>(k+1,0));
// 	int n=arr.size();
// 	for(int i=0;i<n;i++)dp[i][0]=1;
// 	if(arr[0]<=k)dp[0][arr[0]]=1;
// 	for(int i=1;i<n;i++){
// 		for(int sum=0;sum<=k;sum++){
// 			int nottake=dp[i-1][sum];
// 			int take=0;
// 			if(arr[i]<=sum)take=dp[i-1][sum-arr[i]];
// 			dp[i][sum]=(nottake+take)%1000000007;
// 		}
// 	}
// 	return dp[n-1][k];
//     }
//     int recur(vector<int>& nums,int index, int target,int &n,int &ans){
//         //base case
//        // cout<<nums[index]<<" ";
//         if(flag)return ans;
//         if(index==nums.size())return 1e9;
//         if(isthere(nums,target))return 0;
        
//         int breakk=INT_MAX;
//         int notbreak=INT_MAX;
//         if(nums[index]>1){
//             int temp=nums[index];
//             nums.erase(nums.begin()+index);
//             nums.push_back(temp/2);
//             nums.push_back(temp/2);
//             breakk=1+recur(nums,index,target,n,ans);
//             nums.pop_back();
//             nums.pop_back();
//             nums.insert(nums.begin()+index,temp);
//         }
//         notbreak=recur(nums,index+1,target,n,ans);
//         ans=min(breakk,notbreak);
//         if(min(breakk,notbreak)<n){flag=true;return ans;}
//         return ans;
        
//     }
//     int minOperations(vector<int>& nums, int target) {
//         int sum=0;
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++)sum+=nums[i];
//         if(sum<target)return -1;
//         int ans=0;
//        return recur(nums,0,target,n,ans);
//     }
        int minOperations(vector<int>& nums, int target) {
            long long sum=0;
            for(int i=0;i<nums.size();i++)sum+=nums[i];
            if(sum<target)return -1;
            int ans=0;
            sort(nums.begin(),nums.end());
            while(target>0){
                int num=nums.back();
                nums.pop_back();
                if(sum-num>=target)sum-=num;
                else if(num<=target){
                    sum-=num;
                    target-=num;
                }
                else{
                    nums.push_back(num/2);
                    nums.push_back(num/2);
                    ans++;
                }
                if(sum==target)return ans;
            }
            return ans;
    }
};