//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
     void toposort(vector<pair<int,int>> adj[],int node,vector<int> &vis,stack<int> &st){
         vis[node]=1;
         for(auto it:adj[node]){
             if(vis[it.first]!=1){
                 toposort(adj,it.first,vis,st);
             }
         }
         st.push(node);
     }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        //create the graph using edges and weights
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        //step 1. find toposort
        stack<int> st;
        vector<int> vis(N,0);
        for(int i=0;i<N;i++){
            if(vis[i]!=1){
                toposort(adj,i,vis,st);
            }
        }
        //step 2 if you've been given any particular src then pop until you get that src on top
        //otherwise pop and do the distance thing
        vector<int> dis(N);
        for(int i=0;i<N;i++){dis[i]=1e9;}
        dis[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it: adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dis[node]+wt<dis[v]){
                    dis[v]=dis[node]+wt;
                }
            }
        }
        for (int i = 0; i < N; i++) {
        if (dis[i] == 1e9) dis[i] = -1;
      }
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends