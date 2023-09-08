class Solution {
public:
    int atmostk(vector<int>& nums, int k){
        int i=0,j=0;
        map<int,int>mp;
        int ans=0;
        int n=nums.size();
        while(j<n){
            mp[nums[j]]++;
            while(i<=j && mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums,k)-atmostk(nums,k-1);
    }
};