class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=1;
        map<int,int>mp;
        mp[nums[0]]++;
        k++;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(j-i+1>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            if(j-i+1<=k){
                if(mp.size()!=j-i+1)return true;
            }
            j++;
        }
        return false;
    }
};