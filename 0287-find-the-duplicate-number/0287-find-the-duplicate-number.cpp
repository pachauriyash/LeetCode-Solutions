class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      /* 
        //better approach
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])]<0){
                return abs(nums[i]);
            }
            else{
                nums[abs(nums[i])]*=-1;
            }
        }
        return -1;
        */
        //best approach slow and fast pointer
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
            
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};