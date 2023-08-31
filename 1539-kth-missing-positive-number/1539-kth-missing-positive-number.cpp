class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++)mp[arr[i]]++;
        int i=1;
        while(k>0){
            if(mp.find(i)==mp.end())k--;
            i++;
        }
        return i-1;
    }
};