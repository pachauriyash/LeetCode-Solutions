class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi=0;
        for(int i=0;i<s.length();i++){
            int open=0;
            for(int j=i;j<s.length();j++){
                if(s[j]=='(')open++;
                else{
                    if(open>0){
                        open--;
                    }
                    else{break;}
                    if(open==0){
                        maxi=max(maxi,j-i+1);
                    }
                }
            }
        }
        return maxi;
    }
};