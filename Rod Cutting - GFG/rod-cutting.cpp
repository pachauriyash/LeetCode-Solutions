//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int recur(int index, int n,int price[],vector<vector<int>>&dp){
        //base case
        if(index==0){
            return n*price[0];
        }
       
        if(dp[index][n]!=-1)return dp[index][n];
        int notpick=0+recur(index-1,n,price,dp);
        int pick=INT_MIN;
        if(index+1<=n)pick=price[index]+recur(index,n-(index+1),price,dp);
        return dp[index][n]=max(pick,notpick);
    }
    
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return recur(n-1,n,price,dp);
        //tabulation
    //      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //      for(int w=0;w<=n;w++){
    //          if(n<=w){dp[n][w]=price[n-1];}
    //      }
    //      for(int index=n-1;index>=1;index--){
    //       for(int weight=0; weight<=n;weight++){
    //           int notpick=0+dp[index+1][weight];
    //             int pick=INT_MIN;
    //             if(index<=weight)pick=price[index-1]+dp[index+1][weight-index];
    //           dp[index][weight]=max(pick,notpick);
    //       }
    //   }
    //   return dp[n][n];
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