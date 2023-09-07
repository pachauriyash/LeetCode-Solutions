//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool check(map<char,int>&mp1,map<char,int>&mp2){
        for(auto it:mp1){
            if(mp2.find(it.first)==mp2.end())return false;
            else{
                if(mp2[it.first]!=it.second)return false;
            }
        }
        return true;
    }
	int search(string pat, string txt) {
	    int i=0,j=0,count=0;
	    //map<char,int>mp2,mp;
	    vector<int> freq_p(26,0);
        vector<int> window(26,0);
	    int n=pat.size();
	    for(int i=0;i<n;i++){
	     //   mp2[pat[i]]++;
	     freq_p[pat[i]-'a']++;
	    }
        while(j<txt.size()){
            //mp[txt[j]]++;
            window[txt[j]-'a']++;
            if(j-i+1==n){
                // if(mp.size()==mp2.size() && check(mp,mp2)){
                //     count++;
                // }
                // mp[txt[i]]--;
                // if(mp[txt[i]]==0)mp.erase(txt[i]);
                if(freq_p==window){
	                count++;
	            }
                window[txt[i]-'a']--;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends