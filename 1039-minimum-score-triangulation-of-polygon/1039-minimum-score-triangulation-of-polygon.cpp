class Solution {
public:
    int recur(int i,int j,vector<int>& arr,vector<vector<int>>&dp){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+recur(i,k,arr,dp)+recur(k+1,j,arr,dp);
        if(steps<mini)mini=steps;
    }
    return dp[i][j]=mini;
}
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size()-1;
         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return recur(1,n,values,dp);
    }
};