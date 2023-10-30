class Solution {
public:
    bool static comp(int a,int b){
        int counta=0,na=a;
        int countb=0,nb=b;
        while (na) {
            counta += na & 1;
            na >>= 1;
        }
        while (nb) {
            countb += nb & 1;
            nb >>= 1;
        }  
        if(counta==countb){
            return a<b;
        }
        return counta<countb; 

    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};