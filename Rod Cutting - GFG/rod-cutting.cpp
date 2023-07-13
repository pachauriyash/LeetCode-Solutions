//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int recur(int index,int weight, int n,int val[],vector<vector<int>>&dp){
        //base case
        if(index==n){
            if(index<=weight){return val[n-1];}
            else return 0;
        }
       
        if(dp[index][weight]!=-1)return dp[index][weight];
        int notpick=0+recur(index+1,weight,n,val,dp);
        int pick=INT_MIN;
        if(index<=weight)pick=val[index-1]+recur(index,weight-index,n,val,dp);
        return dp[index][weight]=max(pick,notpick);
    }
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return recur(1,n,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends