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
        //memoriation TC O(N*N) SC O(N*N)+O(N)
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return recur(n-1,n,price,dp);
        //tabulation TC O(N*N) SC O(N*N)
         vector<vector<int>>dp(n,vector<int>(n+1,0));
         for(int N=0;N<=n;N++){
            dp[0][N]=N*price[0];
         }
         for(int index=1;index<n;index++){
          for(int N=0; N<=n;N++){
              int notpick=0+dp[index-1][N];
                int pick=INT_MIN;
                if(index+1<=N)pick=price[index]+dp[index][N-(index+1)];
              dp[index][N]=max(pick,notpick);
          }
      }
      return dp[n-1][n];
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