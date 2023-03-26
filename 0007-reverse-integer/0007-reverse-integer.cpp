class Solution {
public:
    int reverse(int x) {
        vector<int> temp;
        int absx=abs(x);
        long t=10;
        while(absx>0){
            int tem=absx%t;
            temp.push_back(tem/(t/10));
            absx=absx-(tem);
            t*=10;
        }
        t=1;
        long sum=0;
        for(int i=temp.size()-1;i>=0;i--){
           sum+=temp[i]*t;
            t*=10;
        }
        if(sum>=2147483648){sum=0;}
        if(x<0){sum*=-1;}
        return int(sum);
        
    }
};