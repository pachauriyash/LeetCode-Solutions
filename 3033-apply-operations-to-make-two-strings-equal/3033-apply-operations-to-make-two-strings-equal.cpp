class Solution {
public:
    int recur(vector<int>&vt,int i,int x,int j,map<pair<int,int>,int>&mp){
        if(i>=j){return 0;}

        if(mp.find({i,j})!=mp.end())return mp[{i,j}];
        int cost=INT_MAX;
        cost=min(cost,min(x,abs(vt[i]-vt[i+1]))+recur(vt,i+2,x,j,mp));
        cost=min(cost,min(x,abs(vt[j]-vt[j-1]))+recur(vt,i,x,j-2,mp));
        cost=min(cost,min(x,abs(vt[i]-vt[j]))+recur(vt,i+1,x,j-1,mp));

        mp.insert({{i,j},cost});
        return cost;
    }
    int minOperations(string s1, string s2, int x) {
        vector<int>numbers;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])numbers.push_back(i);
        }
        if(numbers.size()%2==1)return -1;
        map<pair<int,int>,int> mp;
        return recur(numbers,0,x,numbers.size()-1,mp);

    }
};