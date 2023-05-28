class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){return 1.0;}
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        double ans;
        if(n<0){
            ans= (1/x)*myPow(x,n+1);
        }
        if(n>0){
             ans= x*myPow(x,n-1);
        }
        return ans;
    }
};