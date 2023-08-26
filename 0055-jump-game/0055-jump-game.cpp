class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool>ans(nums.size(),false);
        ans[nums.size()-1]=true;
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=1;j<=nums[i] && i+j<nums.size();j++){
                ans[i]=ans[i] || ans[i+j];
                if(ans[i]==true)break;
            }
        }
        return ans[0];
    }
};