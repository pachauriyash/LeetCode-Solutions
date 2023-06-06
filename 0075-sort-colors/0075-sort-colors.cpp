class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
        int red=0;
        int white=0;
        int blue=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){red++;}
            if(nums[i]==1){white++;}
            if(nums[i]==2){blue++;}
        }
        int i=0;
        while(i<nums.size()){
            if(red>0){
                nums[i]=0;
                red--;
            }else if(white>0 && red==0){
                nums[i]=1;
                white--;
            }
            else{
                nums[i]=2;
                blue--;
            }
            i++;
        } */
        //best approach in one iteration and O(1) space
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};