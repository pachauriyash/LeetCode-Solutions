class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int maxi=nums[0];
        int diff=-1;
        for(int i=1;i<nums.size();i++){
            if(maxi-nums[i]>diff){
               for(int j=i+1;j<nums.size();j++){
                    ans=max(ans,(long long)(maxi-nums[i])*nums[j]);    
                }
                diff=maxi-nums[i]; 
            }
            maxi=max(maxi,nums[i]);
        }
        return ans;
    }
};