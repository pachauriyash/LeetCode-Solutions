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
            //main game is of base case if you're at 0th index then forget about not pick bcz its your loss, think otherwise the max time you can choose that item would be weight/wt[0] and the total value you'll get will be the given one multiplied with val[0];
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
    {   //memoriation TC )(N*W) SC O(N*W)+O(N)
        // vector<vector<int>>dp(N,vector<int>(W+1,-1));
        // return recur(N-1,W,wt,val,dp);
        //tabulation TC O(N*M) SC O(N*M)
       vector<vector<int>>dp(N,vector<int>(W+1,0));
       for(int i=wt[0];i<=W;i++)dp[0][i]=(i/wt[0])*val[0];
       for(int index=1;index<N;index++){
           for(int w=0; w<=W;w++){
               int notpick=0+dp[index-1][w];
               int pick=INT_MIN;
               if(wt[index]<=w)pick=val[index]+dp[index][w-wt[index]];
               dp[index][w]=max(pick,notpick);
           }
       }
       return dp[N-1][W];
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