class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //TC O(NlogN) SC O(1)
        // sort(nums.begin(),nums.end());
        // int index=0;
        // while(index<nums.size() && nums[index]<=0){
        //     index++;
        // }
        // if(index==nums.size())return 1;
        // int val=1;
        // for(;index<nums.size();index++){
        //     if(index!=0 && nums[index]==nums[index-1])continue;
        //     if(nums[index]==val){val++;}
        //     else{return val;}
        // }
        // return val;
        
        //TC O(1) SC O(1)
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
        //         swap(nums[i],nums[nums[i]-1]);
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(nums[i]==i+1){continue;}
        //     else{return i+1;}
        // }
        // return n+1;
        for(int i=0;i<n;i++){
            //if(i!=0 && nums[i]==nums[i-1])continue;
            // if(nums[i]>0 && nums[i]<=n && nums[i]!=i+1 && i!=0 && nums[i]!=nums[i-1]){
            //     swap(nums[nums[i]-1],nums[i]);
            //     i--;
            // }
            while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};