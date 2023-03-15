// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        // int small=arr[0];
        // int small_index;
        // int large=arr[0];
        // int large_index;
        // for(int i=0;i<n;i++){
        //     if(arr[i]<small){
        //         small=arr[i];
        //         small_index=i;
        //     }
        //     if(arr[i]>large){
        //         large=arr[i];
        //         large_index=i;
        //     }
        // }
        
        //     for(int i=0;i<n;i++){
        //         if(arr[i]<k){
        //             arr[i]=arr[i]+k;
        //         }
        //         else{
        //             arr[i]=arr[i]-k;
        //         }
        //     }
        sort(arr,arr+n);
        int mini,maxi,diff;
        diff=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++){
            
            mini=min(arr[0]+k,arr[i+1]-k);
            maxi=max(arr[n-1]-k,arr[i]+k);
            if(mini<0){
                continue;
            }
            diff=min(diff,maxi-mini);
        }
        return diff;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends