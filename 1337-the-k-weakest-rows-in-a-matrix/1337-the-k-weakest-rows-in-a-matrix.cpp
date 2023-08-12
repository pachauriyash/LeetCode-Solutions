class Solution {
public:
    bool static comp(pair<int,int>p1,pair<int,int>p2){
        if(p1.first<p2.first){
            return true;
        }else if(p1.first==p2.first){
            if(p1.second<p2.second){return true;}
        }
        return false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>mp;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){count++;}
            }
            mp.push_back({count,i});
        }
        vector<int>ans;
        sort(mp.begin(),mp.end(),comp);
        int count=0;
        for(auto it:mp){
            count++;
            ans.push_back(it.second);
            if(count==k)break;
        }
        return ans;
    }
};