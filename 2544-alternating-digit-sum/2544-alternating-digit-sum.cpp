class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int>digi;
        while(n>0){
            digi.insert(digi.begin(),n%10);
            n/=10;
        }
        int ans=0;
        for(int i=0;i<digi.size();i++){
            if(i%2==0){
                ans+=digi[i];
            }else{
                ans-=digi[i];
            }
        }
        return ans;
    }
};