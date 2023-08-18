class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // for(int i=0;i<nums.size()-1;i+=2){
        //     if(nums[i]!=nums[i+1]){return nums[i];}
        // }
        // return nums[nums.size()-1];
        int high=nums.size()-2;
        int low=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1])low=mid+1;
                else{high=mid-1;}
            }
            else{
                if(nums[mid]==nums[mid+1])high=mid-1;
                else{low=mid+1;}
            }
        }
        return nums[low];
    }
};