class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,vector<int>>mp;
        if(trust.size()==0 && n==1){return n;}
        // else{return -1;}
        for(int i=0;i<trust.size();i++){
            mp[trust[i][1]].push_back(trust[i][0]);
        }
        int ans=-1;
        for(auto it:mp){
            if(it.second.size()==n-1){ans=it.first;break;}
        }
        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==ans && trust[i][1]!=ans){ans=-1;break;}
            if(ans==-1)break;
        }
        // for(int i=1;i<=n;i++){
        //     if(mp.find(i)!=mp.end()){
        //         if(mp[i].size()==1 && mp[i][0]==i){ans=i;break;}
        //     }
        //     else{ans=i;break;}
        // }
        
        return ans;
    }
};