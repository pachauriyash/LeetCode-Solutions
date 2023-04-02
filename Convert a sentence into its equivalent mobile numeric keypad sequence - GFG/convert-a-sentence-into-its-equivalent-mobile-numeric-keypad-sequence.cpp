//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}

// } Driver Code Ends

string output(char c){
    string temp="";
    if(c=='A'||c=='B'||c=='C'){
        int t= int(c-'A')+1;
        for(t;t>0;t--){temp+='2';}
    }
    else if(c=='D'||c=='E'||c=='F'){
        int t= int(c-'D')+1;
        for(t;t>0;t--){temp+='3';}
    }
    else if(c=='G'||c=='H'||c=='I'){
        int t= int(c-'G')+1;
        for(t;t>0;t--){temp+='4';}
    }
    else if(c=='J'||c=='K'||c=='L'){
        int t= int(c-'J')+1;
        for(t;t>0;t--){temp+='5';}
    }
    else if(c=='M'||c=='N'||c=='O'){
        int t= int(c-'M')+1;
        for(t;t>0;t--){temp+='6';}
    }
    else if(c=='P'||c=='Q'||c=='R'||c=='S'){
        int t= int(c-'P')+1;
        for(t;t>0;t--){temp+='7';}
    }
    else if(c=='T'||c=='U'||c=='V'){
        int t= int(c-'T')+1;
        for(t;t>0;t--){temp+='8';}
    }
    else if(c=='W'||c=='X'||c=='Y'||c=='Z'){
        int t= int(c-'W')+1;
        for(t;t>0;t--){temp+='9';}
    }
    else{
        temp+='0';
    }
    return temp;
}
string printSequence(string S)
{
    string ans="";
    for(int i=0;i<S.size();i++){
        ans+=output(S[i]);
    }
    return ans;
}