class Solution {
public:
    int missingNumber(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]!=1){
                ans=nums[i]-1;
                return nums[i]-1;
            }
        }
        if(nums[nums.size()-1]!=nums.size()){ans=nums.size();}
        if(nums[0]!=0){ans=0;}
    return ans;
    }
    
};