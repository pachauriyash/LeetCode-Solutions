//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void recur(vector<vector<int>> &m, int n,vector<string>&ans,int row,int col, string temp){
        //base case
        if(row==0 && col==0){
            m[row][col]=0;
        }
        if(row==n-1 && col==n-1){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<4;i++){
            if(isvalid(m,n,row,col,i)){
                if(i==0){
                    m[row-1][col]=0;
                    recur(m,n,ans,row-1,col,temp+whatname(i));
                    m[row-1][col]=1;
                }
                else if(i==1){
                    m[row+1][col]=0;
                    recur(m,n,ans,row+1,col,temp+whatname(i));
                    m[row+1][col]=1;
                }
                else if(i==2){
                    m[row][col-1]=0;
                    recur(m,n,ans,row,col-1,temp+whatname(i));
                    m[row][col-1]=1;
                }
                else{
                    m[row][col+1]=0;
                    recur(m,n,ans,row,col+1,temp+whatname(i));
                    m[row][col+1]=1;
                }
            }
        }
    }
    bool isvalid(vector<vector<int>> &m,int n,int row,int col,int i){
        if(i==0){
            if(row-1>=0 && m[row-1][col]==1){return true;}
            else{return false;}
        }
        else if(i==1){
            if(row+1<n && m[row+1][col]==1){return true;}
            else{return false;}
        }
        else if(i==2){
            if(col-1>=0 && m[row][col-1]==1){return true;}
            else{return false;}
        }
        else{
            if(col+1<n && m[row][col+1]==1){return true;}
            else{return false;}
        }
        return false;
    }
    string whatname(int i){
        if(i==0){
            return "U";
        }
        else if(i==1){
            return "D";
        }
        else if(i==2){
            return "L";
        }
        else{
            return "R";
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0){return ans;}
        recur(m,n,ans,0,0,"");
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends