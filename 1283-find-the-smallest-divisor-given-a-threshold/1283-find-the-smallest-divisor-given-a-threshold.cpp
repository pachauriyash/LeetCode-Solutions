class Solution {
public:
    int returnsum(vector<int>& nums,int div){
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=ceil(nums[i]/(double)div);
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=INT_MIN;
        for(int i=0;i<nums.size();i++){
            //low=min(low,nums[i]);
            high=max(high,nums[i]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int res=returnsum(nums,mid);
            if(res>threshold){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};