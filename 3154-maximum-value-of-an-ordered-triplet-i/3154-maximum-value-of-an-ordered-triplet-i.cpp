class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        priority_queue<int>st;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            int maxi=st.top();
            cout<<maxi<<" ";
            for(int j=i+1;j<nums.size();j++){
                ans=max(ans,(long long)(maxi-nums[i])*nums[j]);    
            }
            st.push(nums[i]);
        }
        return ans;
    }
};