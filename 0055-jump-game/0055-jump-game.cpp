class Solution {
public:
    bool canJump(vector<int>& nums) {
        //naive or kinda dp like approach but I can do it with DP as well(have done it in one cs mock interview infact a better verion of it)
        // vector<bool>ans(nums.size(),false);
        // ans[nums.size()-1]=true;
        // for(int i=nums.size()-2;i>=0;i--){
        //     for(int j=1;j<=nums[i] && i+j<nums.size();j++){
        //         ans[i]=ans[i] || ans[i+j];
        //         if(ans[i]==true)break;
        //     }
        // }
        // return ans[0];
        //greedy approach as solving this in greedy section(seen from comments)
        int maxindexreached=0;
        for(int i=0;i<nums.size();i++){
            if(maxindexreached<i)return false;//bcz i can't even reach this current index
            maxindexreached=max(maxindexreached,i+nums[i]);
        }
        return true;
    }
};