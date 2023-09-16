class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        //so to avoid tle  you have to store previous found value
        // int count=0;
        // for(int i=0;i<coordinates.size();i++){
        //     for(int j=i+1;j<coordinates.size();j++){
        //         if((coordinates[i][0] ^ coordinates[j][0])+(coordinates[i][1] ^ coordinates[j][1])==k)count++;
        //     }
        // }
        // return count;

        //optimal solution
        map<vector<int>,int>mp;
        for(auto&it:coordinates){
            mp[it]++;
        }
        long long ans=0;
        for(auto&it:coordinates){
            mp[it]--;
            for(int i=0;i<=k;i++){
                if(mp.find({it[0]^i,it[1]^(k-i)})!=mp.end()){
                    ans+=mp[{it[0]^i,it[1]^(k-i)}];
                }
            }
            mp[it]++;
        }
        return ans/2;
    
    }
};