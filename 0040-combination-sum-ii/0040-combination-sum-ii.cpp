class Solution {
public:
    
    void recur(vector<vector<int>>&ans,vector<int>& candidates,vector<int>&temp,int target,int index){
       
            if(target==0){
                ans.push_back(temp);
                return;
            }
        
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){continue;}
            if(candidates[i]>target){break;}
            temp.push_back(candidates[i]);
            recur(ans,candidates,temp,target-candidates[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        recur(ans,candidates,temp,target,0);
        return ans;
    }
};