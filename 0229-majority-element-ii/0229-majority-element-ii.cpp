class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int el1=INT_MAX;
        int el2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(count1==0 && el2!=nums[i]){
                el1=nums[i];
                count1=1;
            }
            else if(count2==0 && el1!=nums[i]){
                el2=nums[i];
                count2=1;
            }
            else if(nums[i]==el1){
                count1++;
            }
            else if(nums[i]==el2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int count11=0;
        int count22=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1){
                count11++;
            }
            if(nums[i]==el2){
                count22++;
            }
        }
        if(count11>nums.size()/3){
            ans.push_back(el1);
            
        }
        if(count22>nums.size()/3){
             ans.push_back(el2);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};