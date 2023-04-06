class Solution {
public:
    bool isbalanced(string t){
        int i=0;
        int j=t.size()-1;
        while(i<j){
            if(!(t[i]=='0' && t[j]=='1')){return false;}
            i++;
            j--;
        }
        return true;
    }
    int findTheLongestBalancedSubstring(string s) {
        int max=0;
        for(int i=0;i<s.size();i++){
            string temp="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                if(temp.size()%2==0){
                    if(isbalanced(temp)){
                        if(temp.size()>=max){max=temp.size();}
                    }
                }
            }
        }
        return max; 
        //return isbalanced("1100");
    }
};