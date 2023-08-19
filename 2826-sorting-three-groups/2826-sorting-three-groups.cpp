class Solution {
public:
    void recur(vector<int>& nums,int count,int index,int &ans){
        //base case
        if(index==nums.size()){
        //       vector<int>temp2=nums;
        // sort(temp2.begin(),temp2.end());
        // if(temp2==nums)ans=min(ans,count);
            ans=min(ans,count);
            return;
        }
      
        if(index==0){recur(nums,count,index+1,ans);}
        if(index!=0 && nums[index]>=nums[index-1])recur(nums,count,index+1,ans);
        for(int i=1;i<=3;i++){
            if(index==0){
                if(i!=nums[index]){
                int temp=nums[index];
                nums[index]=i;
                recur(nums,count+1,index+1,ans);
                nums[index]=temp;
                }
            }
            if(index!=0 && i>=nums[index-1]){
                if(i!=nums[index]){
                int temp=nums[index];
                nums[index]=i;
                recur(nums,count+1,index+1,ans);
                nums[index]=temp;
            }
            }
            
        }
    }
    int minimumOperations(vector<int>& nums) {
        int ans=INT_MAX;
        recur(nums,0,0,ans);
        return ans;
    }
};