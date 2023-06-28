//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //using priority queue
        /*
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i=0;i<V;i++)dist[i]=1e9;
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int currdis=it[1];
                int adjnode=it[0];
                if(currdis+dis<dist[adjnode]){
                    dist[adjnode]=currdis+dis;
                    pq.push({dist[adjnode],adjnode});
                }
                
            }
        }
        return dist;
        */
        //using set
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        st.insert({0,S});
        dist[S]=0;
        while(!st.empty()){
            auto it=*(st.begin());
            int node= it.second;
            int dis= it.first;
            st.erase(it);
            for(auto it: adj[node]){
                int adjNode=it[0];
                int edgeW=it[1];
                if(dis+edgeW<dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode]=dis+edgeW;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends