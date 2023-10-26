class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>ans;
        //sort(flowers.begin(),flowers.end());
        // for(int i=0;i<people.size();i++){
        //     int count=0;
        //     for(int j=0;j<flowers.size();j++){
        //         if(people[i]>=flowers[j][0] && people[i]<=flowers[j][1])count++;
        //     }
        //     ans.push_back(count);
        // }
        vector<int>start,end;
        for(auto it:flowers){
            start.push_back(it[0]);
            end.push_back(it[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(auto it:people){
            int started=upper_bound(start.begin(),start.end(),it)-start.begin();
            int ended=lower_bound(end.begin(),end.end(),it)-end.begin();
            ans.push_back(started-ended);
        }
        return ans;
    }
};