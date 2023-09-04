class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st;
        long long maxi=INT_MIN;
        for(auto it:nums){
            st.insert(it);
            maxi=max(maxi,(long long)it);
        }
        int i=1;
        while(i<=abs(maxi)+1){
            if(st.find(i)==st.end())return i;
            i++;
        }
        return -1;
    }
};