class Solution {
public:
    void sortColors(vector<int>& nums) {
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
        }
    }
};