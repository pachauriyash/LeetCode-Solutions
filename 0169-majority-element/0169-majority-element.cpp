class Solution {
public:
    int majorityElement(vector<int>& nums) {
      /*
        sort(nums.begin(),nums.end());
       int count=1;
       for(int i=1;i<nums.size();i++){
           if(nums[i]==nums[i-1]){count++;}
           else{
               if(count>(nums.size()/2)){
                   return nums[i-1];
               }
               else{ count=1;}
           }
             if(count>(nums.size()/2)){
                   return nums[i];
               }
       } 
       return nums[0]; */
        //better approach can be using hashmap
        //optimised approach would be using moore's voting
        int element;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                element=nums[i];
                count++;
            }
            else if(nums[i]==element){
                count++;
            }
            else{
                count--;
            }
        }
        int count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==element){count2++;}
        }
        if(count2>nums.size()/2){return element;}
        return -1;
    }
};