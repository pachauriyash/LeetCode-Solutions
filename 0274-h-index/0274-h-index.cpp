class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int maxi=INT_MIN,n=citations.size();
        int i=0,j=INT_MIN;
        for(int k=0;k<citations.size();k++){
            //i=min(i,citations[k]);
            j=max(k,citations[k]);
        }
        while(i<=j){
            int mid=(i+j)/2;
            int index=lower_bound(citations.begin(),citations.end(),mid)-citations.begin();
            if(n-index>=mid){
                maxi=max(maxi,mid);
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
       
        return maxi;
    }
};