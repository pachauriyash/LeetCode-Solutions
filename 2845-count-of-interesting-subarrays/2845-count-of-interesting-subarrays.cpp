class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        map<int,int>mp;
        int count=0;
        long long res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%modulo==k)count++;
            if(count%modulo==k)res++;
            res+=mp[(count+modulo-k)%modulo];
            mp[count%modulo]++;
        }
        return res;
    }
};