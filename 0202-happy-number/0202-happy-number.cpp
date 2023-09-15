class Solution {
public:
    unordered_map<int,bool>mp;
    bool isHappy(int n) {
        if(n==1)return true;
        if(mp[n]==true)return false;
        int sum=0;
        mp[n]=true;
        while(n>0){
            sum+=pow(n%10,2);
            n=n/10;
        }
        return isHappy(sum);
    }
};