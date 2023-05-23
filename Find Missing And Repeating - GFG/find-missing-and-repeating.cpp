//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])==mp.end()){
                mp.insert({arr[i],1});
            }
            else{
                mp.find(arr[i])->second=2;
                ans.push_back(arr[i]);
            }
        }
        int i=1;
        while(i<=n){
            if(mp.find(i)==mp.end()){ans.push_back(i);break;}
            i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends