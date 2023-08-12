class Solution {
public:
    void recur(long long n,int &mini,int steps){
        if(n==1){
            mini=min(mini,steps);
            return;
        }
        if(n%2==0)recur(n/2,mini,steps+1);
        if(n%2==1){
            recur(n+1,mini,steps+1);
            recur(n-1,mini,steps+1);
        }
    }
    int integerReplacement(int n) {
        int mini=INT_MAX;
        recur(n,mini,0);

        return mini;
    }
};