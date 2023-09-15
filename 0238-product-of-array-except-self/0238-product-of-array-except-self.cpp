class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numzeros=0;
        int product=1;
        for(auto it:nums){
            if(it!=0)product*=it;
            else numzeros++;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(numzeros>0){
                if(nums[i]==0){
                    if(numzeros>1)ans.push_back(0);
                    else{ans.push_back(product);}
                }else{
                    ans.push_back(0);
                }
            }else{
                ans.push_back(product/nums[i]);
            }
        }
        return ans;
    }
};