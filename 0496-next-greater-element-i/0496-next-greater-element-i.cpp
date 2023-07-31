class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),-1);
        // for(int i=0;i<nums1.size();i++){
        //     int bools=false;
        //     for(int j=0;j<nums2.size();j++){
        //         if(nums1[i]==nums2[j]){bools=true;}
        //         if(bools && nums2[j]>nums1[i]){ans[i]=nums2[j];break;}
        //     }
        // }
        // return ans;
        map<int,int> mp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top())st.pop();
                if(!st.empty())mp.insert({nums2[i],st.top()});
                st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])!=mp.end()){ans[i]=mp[nums1[i]];}
        }
        return ans;
    }
};