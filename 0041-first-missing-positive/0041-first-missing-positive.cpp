class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index=0;
        while(index<nums.size() && nums[index]<=0){
            index++;
        }
        if(index==nums.size())return 1;
        int val=1;
        for(;index<nums.size();index++){
            if(index!=0 && nums[index]==nums[index-1])continue;
            if(nums[index]==val){val++;}
            else{return val;}
        }
        return val;
    }
};