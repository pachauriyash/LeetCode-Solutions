class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
       map<int,int> m;
            for(int i=0;i<nums1.size();i++){
                if(m.find(nums1[i])==m.end()){
                    m.insert({nums1[i],1});
                }
            }
            for(int i=0;i<nums2.size();i++){
                if(m.find(nums2[i])!=m.end()){
                    m.find(nums2[i])->second++;
                }
            }
        for (auto i : m)
            if(i.second>1){ans.push_back(i.first);}
        
        return ans;
        
    }
};