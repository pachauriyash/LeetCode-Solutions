class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){return nums[i];}
            if(mp.find(nums[i])==mp.end()){
                mp.insert({nums[i],1});
            }
        }
        return 0; */
        //better optimisation
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0){
                return abs(nums[i]);
            }
            else{
                nums[abs(nums[i])-1]*=-1;
            }
        }
        return 0;
    }
};