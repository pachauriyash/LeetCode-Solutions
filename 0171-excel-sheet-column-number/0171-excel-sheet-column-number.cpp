class Solution {
public:
    
    int titleToNumber(string columnTitle) {
        int len=columnTitle.size();
        long l=1;
        int sum=0;
        for(int i=columnTitle.size()-1;i>=0;i--){
            int temp=int(columnTitle[i])-64;
            sum+=temp*l;
            l=l*26;
        }
        return sum;
    }
};