class Solution {
public:
    long long stringdeci(string s,int &maxi){
        long long ans=0;
        long long mul=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                ans+=mul*0;
            }
            else{
                ans+=mul*1;
            }
            mul=mul*2;
            if(mul>maxi)return -1;
        }
        return ans;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        map<int,vector<pair<int,int>>>mp;
        int maxi=INT_MAX;
        for(int i=0;i<queries.size();i++){
            maxi=max(maxi,queries[i][0]^queries[i][1]);
        }
        for(int i=0;i<s.size();i++){
            long long val=0;
            for(int j=i;j<s.size();j++){
                if(j-i+1>30)break;
                val = (val << 1) + (s[j] == '1');
                int temp=val;
                // int temp=stringdeci(s.substr(i,j-i+1),maxi);
                // if(temp>maxi)break;
                mp[temp].push_back({i,j});
            }
        }
        
        vector<vector<int>>ans;
        for(int i=0;i<queries.size();i++){
            int C=queries[i][0]^queries[i][1];
            if(mp.find(C)==mp.end()){
                vector<int>temp={-1,-1};
                ans.push_back(temp);
            }
            else{
                auto it=mp[C];
                int imin=it[0].first;
                int imax=it[0].second;
                for(auto i:it){
                    if((i.second-i.first)<(imax-imin)){
                        imin=i.first;
                        imax=i.second;
                    }
                }
                vector<int>temp={imin,imax};
                 ans.push_back(temp);
            }
        }
        return ans;
    }
};