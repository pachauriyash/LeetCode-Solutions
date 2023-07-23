//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        int maxi=0;
        for(int i=0;i<s.length();i++){
            int open=0;
            for(int j=i;j<s.length();j++){
                if(s[j]=='(')open++;
                else{
                    if(open>0){
                        open--;
                    }
                    else{break;}
                    if(open==0){
                        maxi=max(maxi,j-i+1);
                    }
                }
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends