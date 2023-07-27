class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>extra;
        int size=nums.size();
        k=k%size;
        for(int i=size-k;i<size;i++){
            extra.push_back(nums[i]);
        }
        int index=size-k-1;
        for(int i=size-1;i>=k;i--,index--){
            nums[i]=nums[index];
        }
        for(int i=0;i<k;i++){
            nums[i]=extra[i];
        }
    }
};