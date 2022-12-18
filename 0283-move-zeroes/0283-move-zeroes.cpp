class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]==0 && i<nums.size()-count){
                for(int j=i+1;j<nums.size();j++){
                    nums[j-1]=nums[j];
                }
                nums[nums.size()-1]=0;
                count++;
            }
            
        }
    }
};