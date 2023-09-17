class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum=0,maxsum=INT_MIN,minsum=INT_MAX,currmin=0,currmax=0;
        for(auto&it:nums){
            totalsum+=it;
            currmax=max(it,currmax+it);
            maxsum=max(maxsum,currmax);
            currmin=min(it,currmin+it);
            minsum=min(minsum,currmin);
        }
        return maxsum>0?max(maxsum,totalsum-minsum):maxsum;
    }
};