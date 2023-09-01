class Solution {
public:
    
    bool ispossible(vector<int>&stalls,int k,int dist){
    int count=1,last=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-last>=dist){count++;last=stalls[i];}
        if(count==k)return true;
    }
    return count>=k;
}
    
    int maxDistance(vector<int>& stalls, int k) {
        int low=1;
        sort(stalls.begin(),stalls.end());
    //maximum distance between two cows can be this(but maybe if it's more than two cows so this is not the answer but the answer is in this range)

    int high=stalls[stalls.size()-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        //if it's not possible then at right it is not possible so move left
        if(ispossible(stalls,k,mid)){
            low=mid+1;
        }
        else{high=mid-1;}
    }
    return high;
    }
};