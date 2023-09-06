class Solution {
public:
    int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(auto it:nums)sum+=it;
        int i=0,j=0;
        int maxi=0,tempsum=nums[0];
        //maxi=getLongestSubarray(nums,sum-x);
        while(j<nums.size()){
            while(i<=j && tempsum>(sum-x)){
                tempsum-=nums[i];
                i++;
            }
            if(tempsum==(sum-x)){
                maxi=max(maxi,j-i+1);
            }
            j++;
            if(j<nums.size())tempsum+=nums[j];
        }
        if(x==sum)return nums.size();
        if(maxi==0)return -1;
        return nums.size()-maxi;
    }
};