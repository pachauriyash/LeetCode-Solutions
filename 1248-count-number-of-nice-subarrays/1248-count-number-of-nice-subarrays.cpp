class Solution {
public:
    int atmostk(vector<int>& nums, int k){
        int i=0,j=0,ans=0;
        int count=0;
        while(j<nums.size()){
            if(nums[j]%2)count++;
            while(count>k){
                if(nums[i]%2)count--;
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums,k)-atmostk(nums,k-1);
    }
};