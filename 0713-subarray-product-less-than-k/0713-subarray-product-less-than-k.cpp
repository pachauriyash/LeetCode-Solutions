class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int mul=1,ans=0;
        int i=0,j=0;
        while(j<nums.size()){
            mul*=nums[j];
            while(mul>=k && i<=j){
                mul/=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};