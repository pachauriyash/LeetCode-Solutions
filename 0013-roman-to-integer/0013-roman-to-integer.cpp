class Solution {
public:
    int rom(char ch){
        switch(ch){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int sum=0;
        int len=s.length();
       
        for(int i=0;i<len;i++){
            if(rom(s[i])>=rom(s[i+1]) && (i+1<s.length())){
                sum+=rom(s[i]);
            }
            else if(rom(s[i])<rom(s[i+1]) && (i+1<s.length())){
                sum+=(rom(s[i+1])-rom(s[i]));
                i++;
                continue;
            }
            else{
                sum+=rom(s[i]);
            }
            
        }
        return sum;
    }
};