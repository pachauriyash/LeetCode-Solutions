//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int recur(int index,int weight, int wt[],int val[],vector<vector<int>>&dp){
        //base case
        if(index==0){
            return (weight/wt[0])*val[0];
        }
       
        if(dp[index][weight]!=-1)return dp[index][weight];
        int notpick=0+recur(index-1,weight,wt,val,dp);
        int pick=INT_MIN;
        if(wt[index]<=weight)pick=val[index]+recur(index,weight-wt[index],wt,val,dp);
        return dp[index][weight]=max(pick,notpick);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return recur(N-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends