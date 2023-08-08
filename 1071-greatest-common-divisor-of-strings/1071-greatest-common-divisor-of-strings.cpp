class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int gcds=gcd(str1.length(),str2.length());
        if(str1.substr(0,gcds)!=str2.substr(0,gcds)){return "";}
        string temp=str1.substr(0,gcds);
        string temp2="";
        for(int i=0;i<str1.length()/gcds;i++){
            temp2+=temp;
        }
        if(temp2!=str1)return "";
        temp2="";
        for(int i=0;i<str2.length()/gcds;i++){
            temp2+=temp;
        }
        if(temp2!=str2)return "";
        return temp;
    }
};