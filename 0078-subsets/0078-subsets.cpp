class Solution {
public: 
    /* recursion solution
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
    } */
    void recur(vector<vector<int>>&ans,vector<int> nums){
        int n = nums.size();
	
	for (int num = 0; num < (1 << n); num++) {
		vector<int>temp;
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				temp.push_back(nums[i]);
			}
		}
		
			ans.push_back(temp);
		
	}
	sort(ans.begin(), ans.end());
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        recur(ans,nums);
        
        return ans;
    }
};