//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends

bool find(vector<char> t,char s){
    for(int i=0;i<t.size();i++){
        if(t[i]==s){return true;}
    }
    return false;
}
string firstRepChar(string s)
{   
    vector<char> t;
    for(int i=0;i<s.size();i++){
        if(!find(t,s[i])){t.push_back(s[i]);}
        else{string temp="";temp+=s[i];return temp;}
    }
    return "-1";
    //code here.
}