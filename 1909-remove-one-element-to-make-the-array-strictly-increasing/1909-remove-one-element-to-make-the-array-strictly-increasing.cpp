class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            nums.erase(nums.begin()+i);
            bool res=true;
            for(int j=0;j<nums.size()-1;j++){
                if(nums[j+1]<=nums[j]){res=false;break;}
            }
            if(res==true)return true;
            nums.insert(nums.begin()+i,val);
        }
        return false;
    }
};