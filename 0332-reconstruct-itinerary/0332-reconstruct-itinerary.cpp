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
        unordered_map<string,vector<string>>graph;
        for(auto it:tickets){
            graph[it[0]].push_back(it[1]);
        }
        for (auto& [_, destinations] : graph) {
            sort(destinations.rbegin(), destinations.rend());
        }

        vector<string>ans;
        dfs(graph,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};