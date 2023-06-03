class Solution {
public:
    void recur(vector<vector<int>>&ans,vector<int>temp,int k, int target,int index){
        if(target==0 && k==0){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<10;i++){
            if(i>target){break;}
            temp.push_back(i);
            recur(ans,temp,k-1,target-i,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(ans,temp,k,n,1);
        return ans;
    }
};