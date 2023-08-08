class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>tt;
        int temp=1;
        while(temp<=n/2){
            if(n%temp==0){tt.push_back(temp);}
            temp++;
        }
        tt.push_back(n);
        if(k>tt.size())return -1;
        return tt[k-1];
    }
};