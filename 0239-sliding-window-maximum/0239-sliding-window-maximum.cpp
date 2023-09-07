class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // map<int,int>mp;
        // int i=0,j=0;
        // vector<int>ans;
        // while(j<nums.size()){
        //     mp[nums[j]]++;
        //     if(j-i+1==k){
        //         auto it=mp.rbegin();
        //         ans.push_back(it->first);
        //         mp[nums[i]]--;
        //         if(mp[nums[i]]==0)mp.erase(nums[i]);
        //         i++;
        //         j++;
        //     }else{j++;}
        // }
        // return ans;
        
        deque<int>dq;
        int i=0,j=0;
        vector<int>ans;
        while(j<nums.size()){
            while(!dq.empty() && dq.back()<nums[j])dq.pop_back();
            dq.push_back(nums[j]);
            if(j-i+1==k){
                ans.push_back(dq.front());
                if(dq.front()==nums[i])dq.pop_front();
                i++;
                j++;
            }else{j++;}
        }
        return ans;
    }
};