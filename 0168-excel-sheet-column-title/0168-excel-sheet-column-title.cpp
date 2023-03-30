class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
        columnNumber--;
        while(columnNumber>=0){
            int temp=columnNumber%26;
            s+=('A'+temp);
            columnNumber/=26;
            columnNumber--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};