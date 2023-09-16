class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        // sort(citations.begin(),citations.end());
        // int maxi=INT_MIN,n=citations.size();
        // int i=0,j=n;
        // while(i<=j){
        //     int mid=(i+j)/2;
        //     int index=lower_bound(citations.begin(),citations.end(),mid)-citations.begin();
        //     if(n-index>=mid){
        //         maxi=max(maxi,mid);
        //         i=mid+1;
        //     }else{
        //         j=mid-1;
        //     }
        // }
       
        // return maxi;
        //more optimised
        sort(citations.begin(),citations.end());
        int n=citations.size();
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=n)return n;
            else{
                if(n==1 && citations[i]!=0){
                    return 1;
                }
                n--;
            }
        }
        return n;
    }
};