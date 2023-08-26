class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twenty=0;
        //sort(bills.begin(),bills.end());
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)five++;
            else if(bills[i]==10){
                if(five==0)return false;
                else{
                    five--;
                    ten++;
                }
            }
            else{
                if(ten>0 && five>0){
                    twenty++;
                    ten--;
                    five--;
                }
                else if(ten==0 && five>=3){
                    twenty++;
                    five=five-3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};