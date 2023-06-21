class Solution {
public:
    /*double rec(double x,int n){
        if(n<0){
            return (1/x)*myPow(x,n+1);
        }
        if(n>0){
             return x*myPow(x,n-1);
        }
        return 1.0;
    } */
    double myPow(double x, int n) {
       /* if(n==0){return 1.0;}
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        return rec(x,n); */
        long long nn=n;
        if(n<0) nn=nn*-1;
        double ans=1.0;
        while(nn){
            if(nn%2){
                ans=ans*x;
                nn--;
            }
            else{
                x*=x;
                nn=nn/2;
            }
        }
        if(n>0){return ans;}
        return 1.0/ans;
    }
};