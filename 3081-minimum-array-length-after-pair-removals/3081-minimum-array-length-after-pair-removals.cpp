class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        //TC O(N) SC O(1)
        // int n = nums.size(); 
        // int ans = nums.size(); 
        // int i=0,j=(n+1)/2;
        // while(i<n/2 && j<n){
        //     if (nums[i] < nums[j]) {
        //         ans-=2;
        //     }
        //     i++;
        //     j++;
        // }
        // return ans;
        
        //another intuitive solution from discuss forum
        //basically find the max freq element and its freq now if it occurse less than n/2 time means rest all can cancel out each other so if it's even size then 0 or else 1 element will be left
        //but if it's more than n/2 times then rest of all elements will be balanced out by some from this element and rem is ans
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto it:nums){
            mp[it]++;
        }
        int maxi=0;
        for(auto&it:mp){
            maxi=max(maxi,it.second);
        }
        if(maxi<=n/2){
            return n%2;
        }else{
            return maxi-(n-maxi);
        }
    }
};
