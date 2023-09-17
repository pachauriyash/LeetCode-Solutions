class Solution {
public:
    int fun(int n, int k, int budget,vector<int>composition, vector<int> stock, vector<int> cost){
        long long count=0;
        long long low = 0;
        long long high = 1e9;
        while(low<=high){
            long long mid = low +(high-low)/2;
            long long required=0;
            for(int i=0;i<cost.size();i++){
                if((mid*composition[i])-stock[i]>0){
                     required=required+(mid*composition[i]-stock[i])*cost[i];
                }
               
            }
            if(required<=budget){
                count=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return count;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int maxi=0;
        for(int i=0;i<composition.size();i++){
            int alloys=fun(n,k,budget,composition[i],stock,cost);
            maxi=max(maxi,alloys);
        }
        return maxi;
    }
};