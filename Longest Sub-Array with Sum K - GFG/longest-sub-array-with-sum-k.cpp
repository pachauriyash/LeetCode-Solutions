//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int N, int k) 
    { 
        map<int,int> mp;
        int maxcount=0;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=nums[i];
            if(sum==k){
                maxcount=max(maxcount,i+1);
            }
            if(mp.find(sum-k)!=mp.end()){
                maxcount=max(maxcount,i-mp[sum-k]);
            }
            if(mp.find(sum)==mp.end())mp[sum]=i;
        }
        return maxcount;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends