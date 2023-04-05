class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*int s= nums.size();
        int i=0;
        int count=0;
        for(int i=0;i<s;i++){
            if(nums[i]==val){
                for(int j=i;j<s-1;j++){
                    nums[j]=nums[j+1];
                }
                count++;
                //i--;
            }
            
        }  return (s-count);
        */
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[j++]=nums[i];
            }
        }
        return j;        
    }
};