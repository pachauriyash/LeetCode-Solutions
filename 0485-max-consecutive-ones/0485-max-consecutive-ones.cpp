class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                temp++;
            }
            if(nums[i]==0){
                if(count<=temp){count=temp; temp=0;}
                else{temp=0;}
            }
        }
        if(count<=temp){count=temp; temp=0;}
    return count;
    }
};