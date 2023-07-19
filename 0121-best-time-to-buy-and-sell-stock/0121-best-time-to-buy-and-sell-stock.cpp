// #include <cmath>
class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int buy,maxprofit=0;
        // for(int i=0;i<prices.size();i++){
        //     buy=prices[i];
        //     for(int j=i;j<prices.size();j++){
        //         if(prices[j]-buy>maxprofit){
        //            maxprofit=prices[j]-buy; 
        //         }
        //     }
        // }
        buy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>buy){
                maxprofit=max(maxprofit,prices[i]-buy);
            }
            else{
                buy=min(buy,prices[i]);
            }
        }
        return maxprofit;
    }
};