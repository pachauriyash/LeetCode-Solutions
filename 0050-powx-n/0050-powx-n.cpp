class Solution {
public:
    double rec(double x,int n){
        if(n<0){
            return (1/x)*myPow(x,n+1);
        }
        if(n>0){
             return x*myPow(x,n-1);
        }
        return 1.0;
    }
    double myPow(double x, int n) {
        if(n==0){return 1.0;}
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        return rec(x,n);
    }
};