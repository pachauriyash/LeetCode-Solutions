class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       
        priority_queue<pair<int, pair<int, int>>> pq;
        int count=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(count!=k){
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                    count++;
                }else{
                    auto it=pq.top();
                    int sum=nums1[i]+nums2[j];
                    if(sum<it.first){
                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                    }else{
                        break;
                    }
                }
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            vector<int>temp={it.second.first,it.second.second};
            ans.push_back(temp);
        }
        return ans;
    }
};