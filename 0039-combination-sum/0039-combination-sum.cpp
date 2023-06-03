class Solution {
public:
    void recur(vector<vector<int>>&ans,vector<int>& candidates,int target,vector<int> &temp,int index){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            recur(ans,candidates,target-candidates[index],temp,index);
            temp.pop_back();
        }
        
        recur(ans,candidates,target,temp,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(ans,candidates,target,temp,0);
        return ans;
    }
};