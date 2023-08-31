class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) k++; //shifting k
            else break;
        }
        return k;
        // map<int,int>mp;
        // for(int i=0;i<arr.size();i++)mp[arr[i]]++;
        // int i=1;
        // while(k>0){
        //     if(mp.find(i)==mp.end())k--;
        //     i++;
        // }
        // return i-1;
        //binary search
        // int low=0,high=arr.size()-1;
        // while(low<=high){
        //     int mid=(high+low)/2;
        //     int missing=arr[mid]-(mid+1);
        //     if(missing<k){low=mid+1;}
        //     else{high=mid-1;}
        // }
        // if(high==-1){return k;}
        // int missing=k-(arr[high]-(high+1));
        // return arr[high]+missing;
    }
};