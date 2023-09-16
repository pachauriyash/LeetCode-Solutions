class Solution {
public:
    int trailingZeroes(int n) {
        int num5=0,num10=0;
        for(int i=1;i<=n;i++){
            int temp=i;
            if(temp%5==0){
                while(temp%5==0){
                    temp=temp/5;
                    num5++;
                }
            }
            if(temp%10==0){
                while(temp%10==0){
                    temp=temp/10;
                    num10++;
                }
            }
        }
        return num5+num10;
    }
};