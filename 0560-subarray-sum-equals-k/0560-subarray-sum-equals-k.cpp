class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int maxcount=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                maxcount++;
                if(mp.find(sum-k)!=mp.end()){
                    maxcount+=mp[sum-k];
                }
                mp[sum]++;
            }
            else if(mp.find(sum-k)!=mp.end()){
                maxcount+=mp[sum-k];
                mp[sum]++;
            }
            else{
                mp[sum]++;
            }
        }
        return maxcount;
    }
};