class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0;
        bool condition=true;
        while(condition && (i<arr.size()-1)){
            if(arr[i]>arr[i+1]){condition=false;break;}
            else{i++;}
        }  
        int ans=0;
        for(int temp=i;temp<arr.size()-1;temp++){
          if(arr[temp]<arr[temp+1]){ans=1;break;}  
        }
        if(ans==1){return -1;}
        return i;
    }
};