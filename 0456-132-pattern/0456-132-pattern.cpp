class Solution {
public:
    bool find132pattern(vector<int>& nums) {
         if(nums.size()<3)return false;
        
        // for(int i=0;i<nums.size();i++){
        //     set<int>st;
        //     int minindex=i,minvalue=nums[i];
        //     for(int j=minindex+1;j<nums.size();j++){
        //         st.insert(nums[j]);
        //         if(nums[j]>minvalue){
        //             for(auto it:st){
        //                 if(it>nums[j])return true;
        //             }
        //         }
            
        //     }
        // }
        // //cout<<minindex<<" "<<minvalue;
        
        // return false;
        int thirdele=INT_MIN;
        stack<int>decreasingst;
        for(int i=nums.size()-1;i>=0;i--){
            if(thirdele>nums[i])return true;
            while(!decreasingst.empty() && decreasingst.top()<nums[i]){
                thirdele=decreasingst.top();
                decreasingst.pop();
            }
            decreasingst.push(nums[i]);
        }
        return false;
    }
};