class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int>st;
        int n=nums.size();
        for(int i=x;i<n;i++){
            st.insert(nums[i]);
        }
        int ans=INT_MAX;
        for(int i=0;i<n-x;i++){
            auto it=st.lower_bound(nums[i]);
            auto it_back=it;
            if(it!=st.begin()){
                it_back--;
                ans=min(ans,abs(*it-nums[i]));
                ans=min(ans,abs(*it_back-nums[i]));
            }
            else{
                ans=min(ans,abs(*it-nums[i]));
            }
            st.erase(st.find(nums[i+x]));
        }
        return ans;
    }
};