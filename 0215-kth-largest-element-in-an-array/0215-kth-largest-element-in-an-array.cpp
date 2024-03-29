class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //code here
        
        priority_queue<int> pq;
	    for(int i=0;i<nums.size()-k+1;i++){
	        pq.push(nums[i]);
	    }
	    for(int i=nums.size()-k+1;i<nums.size();i++){
	        if(nums[i]<pq.top()){
	            pq.pop();
	            pq.push(nums[i]);
	        }
	    }
	    return pq.top();
    }
};