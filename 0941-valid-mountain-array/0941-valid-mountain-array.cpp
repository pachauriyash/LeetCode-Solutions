class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=0;
        int size=arr.size();
        if(size<3)return false;
        for(i=0;i<size-1;i++){
            if(arr[i]>=arr[i+1]){break;}
        }
        if(i==0 || i==size-1)return false;
        
        for(int j=i;j<size-1;j++){
            if(arr[j]<=arr[j+1]){return false;}
        }
        return true;
        
    }
};