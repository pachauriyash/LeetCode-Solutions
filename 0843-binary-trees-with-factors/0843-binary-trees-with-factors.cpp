class Solution {
public:
    #define mod 1000000007
    int recur(int index,vector<int>&arr,vector<int>&dp){
        //base case
        if(index==0)return dp[index]=1;
        if(dp[index]!=-1)return dp[index];
        long long res=1;
        for(int i=0;i<index;i++){
            if(arr[index]%arr[i]==0){
                for(int j=0;j<index;j++){
                    if(arr[j]==(arr[index]/arr[i])){
                        res=(res%mod+ (long long)(recur(i,arr,dp)%mod)*(recur(j,arr,dp)%mod))%mod;
                    }
                }
            }
        }
        int temp=recur(index-1,arr,dp);
        return dp[index]=res;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        vector<int>dp(arr.size(),-1);
        sort(arr.begin(),arr.end());
        int temp=recur(arr.size()-1,arr,dp);
        int ans=0;
        for(int i=0;i<dp.size();i++){
            ans= (ans+dp[i])%mod;
        }
        return ans;
    }
};