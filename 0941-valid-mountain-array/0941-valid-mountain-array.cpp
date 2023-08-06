class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=0;
        if(arr.size()<3)return false;
        for(i=0;i<arr.size()-1;i++){
            if(arr[i]>=arr[i+1]){break;}
        }
        cout<<i;
        if(i==0 || i==arr.size()-1)return false;
        
        for(int j=i;j<arr.size()-1;j++){
            if(arr[j]<=arr[j+1]){return false;}
        }
        return true;
        
    }
};