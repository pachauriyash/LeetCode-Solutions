//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
        vector<int>dp(nums.size(),1);
        vector<int>dp2(nums.size(),1);
        for(int i=0;i<nums.size();i++){

            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
        }
        for(int i=nums.size()-1;i>=0;i--){

            for(int prev=nums.size()-1;prev>i;prev--){
                if(nums[prev]<nums[i] && 1+dp2[prev]>dp2[i]){
                    dp2[i]=1+dp2[prev];
                }
            }
        }
        int ans=0;
        for(int i=0;i<dp.size();i++){
            ans=max(ans,dp[i]+dp2[i]-1);
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends