class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        int y=s.length();
        int j=y-1;
        if(x>0){
            for(int i=0;i<y/2;i++){
                if(s[i]==s[j]){
                  x=true;
                }
                else{
                    x=false;
                    break;
                }
                j--;
            }
        }
        else if(x==0){
            x=true;
        }
        else{
            x=false;
        }
        
        return x;
    }
};