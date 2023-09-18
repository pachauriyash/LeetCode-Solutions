class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long val=0;
        long long mul=pow(2,31);
        while(n){
            val+= (n & 1)*mul;
            mul/=2;
            n>>=1;
        }
        return val;
    }
};