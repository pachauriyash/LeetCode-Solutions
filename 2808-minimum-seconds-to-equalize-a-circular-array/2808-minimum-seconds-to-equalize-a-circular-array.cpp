class Solution {
public:
    
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int n=nums.size();
        int ans=INT_MAX;
        for(auto it:mp){
            int diff=0;
            if(it.second.size()==n)return 0;
            for(int i=1;i<it.second.size();i++){
                diff=max(diff,it.second[i]-it.second[i-1]-1);
            }
            diff=max(diff,it.second[0]-it.second[it.second.size()-1]+n-1);
            
            ans=min(ans,diff);
        }
        return (ans+1)/2;
    }
};