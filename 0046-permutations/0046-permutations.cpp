class Solution {
public:
    void recur(vector<vector<int>>&ans,vector<int>nums,vector<int>temp){
        if(nums.size()==0){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            vector<int> temp2;
            temp2=nums;
            temp2.erase(temp2.begin()+i);
            temp.push_back(nums[i]);
            recur(ans,temp2,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(ans,nums,temp);
        return ans;
    }
};