//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int maxi=0;
        vector<int>dp(nums.size(),1);
        vector<int>dp2(nums.size(),1);
        for(int i=0;i<nums.size();i++){

            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        reverse(nums.begin(),nums.end());
        int maxi2=0;
        for(int i=0;i<nums.size();i++){

            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp2[prev]>dp2[i]){
                    dp2[i]=1+dp2[prev];
                }
            }
            if(dp2[i]>maxi2){
                maxi2=dp2[i];
            }
        }
        int ans=0;
        reverse(dp2.begin(),dp2.end());
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