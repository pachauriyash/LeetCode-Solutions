class Solution {
public:
    int rob(vector<int>& nums) {
        int curr;
    int prev2=nums[0];
    if(nums.size()==1){return prev2;}
    int prev=max(nums[1],prev2);
    for(int i=2;i<nums.size();i++){
        curr=max(nums[i]+prev2,prev);
        prev2=prev;
        prev=curr;
    }
    return prev;
    }
};