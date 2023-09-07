class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //brute force solution  TC O(N^2) SC O(N*26)
        // vector<vector<int>>freq(strs.size(),vector<int>(26,0));
        // for(int i=0;i<strs.size();i++){
        //     for(int j=0;j<strs[i].size();j++){
        //         freq[i][strs[i][j]-'a']++;
        //     }
        // }
        // vector<vector<string>>ans;
        // vector<int>visited(strs.size(),0);
        // for(int i=0;i<freq.size();i++){
        //     vector<string>temp;
        //     if(visited[i])continue;
        //     temp.push_back(strs[i]);
        //     visited[i]=1;
        //     for(int j=i+1;j<freq.size();j++){
        //         if(freq[j]==freq[i] && visited[j]!=1){
        //             visited[j]=1;
        //             temp.push_back(strs[j]);
        //         }
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
        
        //optimised solution
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto p : mp) { 
            ans.push_back(p.second);
        }
        return ans;
    }
};