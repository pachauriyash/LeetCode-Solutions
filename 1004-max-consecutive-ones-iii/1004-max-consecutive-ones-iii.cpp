class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int numzero=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==0)numzero++;
            while(i<=j && numzero>k){
                if(nums[i]==0)numzero--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};