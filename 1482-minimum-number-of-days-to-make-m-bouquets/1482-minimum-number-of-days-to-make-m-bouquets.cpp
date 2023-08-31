class Solution {
public:
    bool check(vector<int>& bloomDay,int m, int k,int days){
        int count=0,temp=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days)temp++;
            else{temp=0;}
            if(temp==k){
                count++;
                temp=0;
            }
        }
        return count>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int high=0;
        int low=INT_MAX;
        if((long long)m*k>bloomDay.size())return -1;
        for(int i=0;i<bloomDay.size();i++){high=max(bloomDay[i],high);low=min(low,bloomDay[i]);}
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(bloomDay,m,k,mid)){high=mid-1;}
            else{low=mid+1;}
        }
        return low;
    }
};