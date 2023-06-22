class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /* good approach
        sort(nums.begin(),nums.end());
        if(nums.size()==0){return 0;}
        int count=1;
        int maxnum=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){count++;}
            else if(nums[i]==nums[i-1]){continue;}
            else{
                maxnum=max(maxnum,count);
                count=1;
            }
        }
        return max(maxnum,count); */
        // a slightly better approach using unordered set
        int n=nums.size();
        if(n==0){return 0;}
        int longest=1;
        unordered_set<int> ss;
        for(int i=0;i<n;i++){
            ss.insert(nums[i]);
        }
        for(auto it:ss){
            if(ss.find(it-1)==ss.end()){
                int count=1;
                int x=it;
                while(ss.find(x+1)!=ss.end()){
                    count++;
                    x++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};