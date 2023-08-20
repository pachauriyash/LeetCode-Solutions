class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int mostFreq=0,ans=0;
        int i=0,j=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            mostFreq=max(mostFreq,mp[nums[j]]);
            while(j-i+1-mostFreq>k){
                mp[nums[i]]--;
                i++;
            }
            ans=max(ans,mostFreq);
            j++;
        }
        return ans;
    }
};