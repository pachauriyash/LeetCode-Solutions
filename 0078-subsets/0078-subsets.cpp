class Solution {
public:
    void recur(vector<vector<int>> &ans, vector<int> temp,int index,vector<int>& nums){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        recur(ans,temp,index+1,nums);
        temp.pop_back();
        recur(ans,temp,index+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(ans,temp,0,nums);
        return ans;
    }
};