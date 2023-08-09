class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int>digi;
        int ans=0;
        int i=0;
        while(n>0){
            if(i%2==0){
                ans+=n%10;
            }else{
                ans-=n%10;
            }
            i++;
            //digi.insert(digi.begin(),n%10);
            n/=10;
        }
        if(i%2==0)return -ans;
        // for(int i=0;i<digi.size();i++){
        //     if(i%2==0){
        //         ans+=digi[i];
        //     }else{
        //         ans-=digi[i];
        //     }
        // }
        return ans;
    }
};