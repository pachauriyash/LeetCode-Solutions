class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        map<int,int>mp;
        long long ans=0;
        long long sum=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1<k){
                j++;
            }else{
                int size=j-i+1;
                if(mp.size()==size && size==k){
                    ans=max(ans,sum);
                }
                mp[nums[i]]--;
                sum-=nums[i];
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};