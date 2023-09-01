class Solution {
public:
    int numbits(int n){
        int count=0;
        while(n){
            count+= n & 1;
            n>>=1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        // vector<int>ans;
        // for(int i=0;i<=n;i++){
        //     ans.push_back(numbits(i));
        // }
        // return ans;
        
        //optimised sol
        vector<int>ans(n+1);
        ans[0]=0;
        for(int i=1;i<n+1;i++){
            //basically if x is even then it's number of set bits are same as x/2 but if odd then it is 1+ x/2
            ans[i]=ans[i/2]+i%2;
        }
        return ans;
    }
};