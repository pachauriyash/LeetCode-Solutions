class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        while (x && y) {

            count += (x & 1)!=(y & 1);
            x >>= 1;
            y >>= 1;
        }
        if(x!=0){
            while (x) {

                count += (x & 1);
                x >>= 1;
            }
        }
        if(y!=0){
            while (y) {

                count += (y & 1);
                y >>= 1;
            }
        }
        return count;
    }
};