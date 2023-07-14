//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string text1, string text2)
	//so basically the logic is find the subsequnce which is common in both which has to not be touched, now the remaining in first string has to be deleted and similarly the difference from second string also has to be either deleted or added in first string
	{ //space optimised LCsubseq solution
	   vector<int>prev(text2.length()+1,0),curr(text2.length()+1,0);
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1]){curr[j]=1+prev[j-1];}
                else{curr[j]=max(prev[j],curr[j-1]);}
            }
            prev=curr;
        }
        int temp=prev[text2.length()];
        int n=text1.length();
        int m=text2.length();
        return n+m-2*temp;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends