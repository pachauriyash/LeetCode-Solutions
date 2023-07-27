class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int>extra;
        // int size=nums.size();
        // k=k%size;
        // for(int i=size-k;i<size;i++){
        //     extra.push_back(nums[i]);
        // }
        // int index=size-k-1;
        // for(int i=size-1;i>=k;i--,index--){
        //     nums[i]=nums[index];
        // }
        // for(int i=0;i<k;i++){
        //     nums[i]=extra[i];
        // }
        //TLE
        // int size=nums.size();
        // k=k%size;
        // while(k>0){
        //     int temp=nums[size-1];
        //     for(int i=size-1;i>0;i--){
        //         nums[i]=nums[i-1];
        //     }
        //     nums[0]=temp;
        //     k--;
        // }
        int size=nums.size();
        k=k%size;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};