class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int product=1;
        for(int i = 0; i < nums.size(); i++) {
            maxi = max(product *= nums[i], maxi);
            if (nums[i] == 0) product = 1;
        }

 product = 1;
 for(int i = nums.size() - 1; i >= 0; i--) {
     maxi = max(product *= nums[i], maxi);
     if (nums[i] == 0) product = 1;
 }

 return maxi;
    }
};