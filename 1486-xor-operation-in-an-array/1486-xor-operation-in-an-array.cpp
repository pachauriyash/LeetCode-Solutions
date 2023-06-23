class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n);
        int res=0;
        for(int i=0;i<n;i++){
            res=res^(start+2*i);
        }
        return res;
    }
};