
class Solution {

public:
    int numdays(vector<int>& weights, int capacity){
        int count=0,tempsum=0;
        for(int i=0;i<weights.size();i++){
            tempsum+=weights[i];
            if(tempsum>capacity){
                count++;
                tempsum=weights[i];
            }
        }
        return ++count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<weights.size();i++){high+=weights[i];low=max(low,weights[i]);}
        while(low<=high){
            int mid=low+(high-low)/2;
            if(numdays(weights,mid)<=days)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};