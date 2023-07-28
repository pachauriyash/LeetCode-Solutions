class Solution {
public:
    int splitNum(int num) {
        vector<int>nums;
        while(num>0){
            nums.push_back(num%10);
            num=num/10;
        }
        sort(nums.begin(),nums.end(),greater<int>());
        int num1=0;
        int num2=0;
        int mul=1;
        for(int i=0;i<nums.size();i+=2){
             num1+=mul*nums[i];
            mul*=10;
        }
        mul=1;
        for(int j=1;j<nums.size();j+=2){
            num2+=mul*nums[j];
            mul*=10;
        }
        return num1+num2;
    }
};