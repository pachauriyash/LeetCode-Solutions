class Solution {
public:
   /* void recur(int x, int y, int z, string str, int size, int &maxsize) {
        maxsize = max(maxsize, size);
        if (x == 0 && y == 0 && z == 0) {
            return;
        }
        if (size == 0) {
            recur(x - 1, y, z, str + "AA", size + 2, maxsize);
            recur(x, y - 1, z, str + "BB", size + 2, maxsize);
            recur(x, y, z - 1, str + "AB", size + 2, maxsize);
        }
        else if (size >= 2) {
            string temp1 = str.substr(size - 2, 2);
            if (temp1 == "AA") {
                if(y>0)recur(x, y - 1, z, str + "BB", size + 2, maxsize);
            }
            else if (temp1 == "AB") {
                if(x>0)recur(x-1, y, z, str + "AA", size + 2, maxsize);
                if(z>0)recur(x, y, z-1, str + "AB", size + 2, maxsize);
            }
            else if (temp1 == "BB") {
                if(x>0)recur(x - 1, y, z, str + "AA", size + 2, maxsize);
                if(z>0)recur(x, y, z - 1, str + "AB", size + 2, maxsize);
            }

        }
    } */

    int longestString(int x, int y, int z) {
        /* basic brute force but tle
        string temp="";
        int maxsize=0;
        recur(x,y,z,temp,0,maxsize);
        return maxsize; */
        if(x>y){
            return (y+1+y+z)*2;
        }
        else if(x==y){
            return (x+y+z)*2;
        }
        else{
            return (x+x+1+z)*2;
        }
    }
};