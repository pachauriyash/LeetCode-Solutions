//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void gbs(string s,int num,int past){
       if(num==0){
           cout<<s<<" ";
           return;
       }
       gbs(s+'0',num-1,0);
       if(past==1){
           return;
       }
       gbs(s+'1',num-1,1);
    }
    void generateBinaryStrings(int num){
        //Write your code
        string ans="";
        gbs(ans,num,0);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends