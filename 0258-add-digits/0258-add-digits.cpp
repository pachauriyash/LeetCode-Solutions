class Solution {
public:
    int addDigits(int num) {
        if(num==0)return 0;
        int sum=0;
        int count=0;
        while(num>0){
            sum+=num%10;
            num=num/10;
            count++;
        }
        if(count==1){return sum;}
        return addDigits(sum);
    }
};