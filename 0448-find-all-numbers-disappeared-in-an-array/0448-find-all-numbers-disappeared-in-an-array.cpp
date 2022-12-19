class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums){
       /* vector<int> ans;
        for(int i=1;i<=nums.size();i++){
            int val=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==i){
                    val=1;
                    break;
                }
                else{val=0;}
            }
            if(val==0){ans.push_back(i);}
        }
        return ans; */
        vector<int> results;
        
        
        for (int i = 0; i < nums.size(); ++i)
        {
			
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        
        
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                results.push_back(i + 1);
        
        return results;
    
    }
};