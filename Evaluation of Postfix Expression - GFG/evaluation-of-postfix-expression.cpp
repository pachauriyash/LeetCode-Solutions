//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
     bool isoperator(char s){
        if(s=='+' || s=='-' || s=='*' || s=='/'){return true;}
        else{return false;}
    }
    int calcul(int i1,int i2,char s){
        if(s=='+'){
            return (i1+i2);
        }
        else if(s=='-'){
            return (i1-i2);
        }
        else if(s=='*'){
            return (i1*i2);
        }
        else if(s=='/'){
            return (i1/i2);
        }
        else{return 0;}
    }
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for(int i=0;i<S.size();i++){
            if(!isoperator(S[i])){
                st.push(int(S[i]-'0'));
            }
            else{
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
                st.pop();
                int ans=calcul(temp2,temp1,S[i]);
                st.push(ans);
            } 
        }
        int t=st.top();
        st.pop();
        return t; 
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends