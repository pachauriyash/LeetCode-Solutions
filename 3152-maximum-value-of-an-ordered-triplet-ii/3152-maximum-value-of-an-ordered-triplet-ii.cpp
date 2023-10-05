class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // long long ans=0;
        // int maxi=nums[0];
        // int diff=-1;
        // for(int i=1;i<nums.size();i++){
        //     if(maxi-nums[i]>diff){
        //        for(int j=i+1;j<nums.size();j++){
        //             ans=max(ans,(long long)(maxi-nums[i])*nums[j]);    
        //         }
        //         diff=maxi-nums[i]; 
        //     }
        //     maxi=max(maxi,nums[i]);
        // }
        // return ans;

        //better solution
        long long highest=0,highest_diff=0,ans=0;
        for(long long num:nums){
            ans=max(ans,highest_diff*num);
            highest_diff=max(highest_diff,highest-num);
            highest=max(highest,num);
        }
        return ans;
    }
};