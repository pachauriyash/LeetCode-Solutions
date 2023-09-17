class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=x/2;
        if(x==1)return 1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long ans=mid;
            ans=ans*mid;
            if(ans==x)return mid;
            if(ans>x){high=mid-1;}
            else{low=mid+1;}
        }
        return high;
    }
};