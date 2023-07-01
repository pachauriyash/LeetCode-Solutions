class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[index]=nums[i-1];
                index++;
            }
        }
        nums[index]=nums[nums.size()-1];
        index++;
        return index;
    }
};