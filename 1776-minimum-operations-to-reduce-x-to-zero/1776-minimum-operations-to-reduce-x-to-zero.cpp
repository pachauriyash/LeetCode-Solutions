class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //again here also reverse method will be used because we have to choose numbers from left and right ends and find maxi or mini then we'll find a subarray in between for opposite requirements 
        //similar question is https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
        int sum=0;
        for(auto it:nums)sum+=it;
        int i=0,j=0;
        int maxi=0,tempsum=0;

        while(j<nums.size()){
            tempsum+=nums[j];
            while(i<=j && tempsum>(sum-x)){
                tempsum-=nums[i];
                i++;
            }
            if(tempsum==(sum-x)){
                maxi=max(maxi,j-i+1);
            }
            j++;
            //if(j<nums.size())tempsum+=nums[j];
        }
        if(x==sum)return nums.size();
        if(maxi==0)return -1;
        return nums.size()-maxi;
    }
};