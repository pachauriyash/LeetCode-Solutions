class Solution {
public:
    int alternateDigitSum(int n) {
        int ans=0;
        int i=0;
        while(n>0){
            if(i%2==0){
                ans+=n%10;
            }else{
                ans-=n%10;
            }
            i++;
            n/=10;
        }
        if(i%2==0)return -ans;
        return ans;
    }
};