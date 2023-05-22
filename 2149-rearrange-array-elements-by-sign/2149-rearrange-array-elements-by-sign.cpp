class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        int k=0,j=0,i=0;
        nums[i]=pos[k];
        i++;
        k++;
        while(i<nums.size()){
            if(i%2==0){
                nums[i]=pos[k];
                k++;
            }
            if(i%2==1){
                nums[i]=neg[j];
                j++;
            }
            i++;
        }
        return nums;
    }
};