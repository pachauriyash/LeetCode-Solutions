class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size(); 
        int ans = nums.size(); 
        int i=0,j=(n+1)/2;
        while(i<n/2 && j<n){
            if (nums[i] < nums[j]) {
                ans-=2;
            }
            i++;
            j++;
        }
        return ans;
    }
};
