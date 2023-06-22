class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* brute force
        int i,j;
        vector<int> ans;
        for(i=0;i<nums.size();i++){
            for(j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans; 
        */
        map<int,int> data;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            data.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
            if(data.find(target-nums[i])!=data.end() && data[target-nums[i]]!=i){
                ans.push_back(i);
                ans.push_back(data[target-nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};