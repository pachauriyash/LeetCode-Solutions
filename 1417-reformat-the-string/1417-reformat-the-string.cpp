class Solution {
public:
    bool isnum(char c){
        if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9'){return true;}
        return false;
    }
    string reformat(string s) {
        vector<char>num,alpha;
        for(int i=0;i<s.size();i++){
            if(isnum(s[i]))num.push_back(s[i]);
            else alpha.push_back(s[i]);
        }
        if(abs((double)alpha.size()-(double)num.size())>1)return "";
        string ans="";
        if(alpha.size()>=num.size()){
            int i=0,j=0;
            while(i<alpha.size() && j<num.size()){
                ans+=alpha[i];
                ans+=num[j];
                i++;
                j++;
            }
            if(i!=alpha.size()){ans+=alpha[i];}
        }
        else{
            int i=0,j=0;
            while(i<alpha.size() && j<num.size()){
                ans+=num[j];
                ans+=alpha[i];
                i++;
                j++;
            }
            if(j!=num.size()){ans+=num[j];}
        }
        return ans;
    }
};