class Solution {
public:
    void dfs(unordered_map<string,vector<string>>&graph,string airport, vector<string>&ans){
        while(!graph[airport].empty()){
            string next=graph[airport].back();
            graph[airport].pop_back();
            dfs(graph,next,ans);
        }
        ans.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //so basically we are sorting in reverse as while backtracking we are poppping from back so kind of iterating the adjacency list from back so thats why
        sort(tickets.rbegin(),tickets.rend());
        unordered_map<string,vector<string>>graph;
        for(auto it:tickets){
            graph[it[0]].push_back(it[1]);
        }
        vector<string>ans;
        dfs(graph,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};