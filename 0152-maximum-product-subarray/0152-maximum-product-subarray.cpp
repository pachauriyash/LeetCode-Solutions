class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //so from solution we understand that if even number of negatives are there then no worries but in case if odd number of negatives are there then whether we get maxsum using right half negatives or left half is the case so just find answer from both ends;
    //     int maxi=INT_MIN;
    //     int product=1;
    //     for(int i = 0; i < nums.size(); i++) {
    //         maxi = max(product *= nums[i], maxi);
    //         if (nums[i] == 0) product = 1;
    //     }
    //      product = 1;
    // for(int i = nums.size() - 1; i >= 0; i--) {
    //      maxi = max(product *= nums[i], maxi);
    //     if (nums[i] == 0) product = 1;
    // }

    // return maxi;

    //another good solution but idk why everyone says is dp so the logic is taking minproduct and maxproduct from beginning to end and if the nums[i]<0 which means minproduct*nums[i] might give me ans and will be larger than maxproduct so swap them

        int minproduct=1;
        int maxproduct=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                swap(minproduct,maxproduct);
            }
            maxproduct=max(nums[i]*maxproduct,nums[i]);
            minproduct=min(nums[i]*minproduct,nums[i]);
            ans=max(ans,maxproduct);
        }
        return ans;
    }
};