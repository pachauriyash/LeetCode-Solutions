//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{   private:
    int recur(int index,int weight, int wt[],int val[],vector<vector<int>>&dp){
        //base case
        if(index==0){
            if(wt[0]<=weight){return val[0];}
            else return 0;
        }
        if(dp[index][weight]!=-1)return dp[index][weight];
        int notpick=0+recur(index-1,weight,wt,val,dp);
        int pick=INT_MIN;
        if(wt[index]<=weight)pick=val[index]+recur(index-1,weight-wt[index],wt,val,dp);
        return dp[index][weight]=max(pick,notpick);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return recur(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends