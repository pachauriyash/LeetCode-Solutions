class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(first==nums.size() || (first!=nums.size() && nums[first]!=target))return {-1,-1};
        int last=first;
        while(last!=nums.size() && nums[last]==target){
            last++;
        }
        return {first,last-1};
    }
};