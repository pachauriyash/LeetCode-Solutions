class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool incre=true;
        bool decre=true;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])incre=false;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i])decre=false;
        }
        return incre || decre;
    }
};