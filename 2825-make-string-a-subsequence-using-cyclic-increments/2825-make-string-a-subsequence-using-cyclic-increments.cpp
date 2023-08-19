class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int index1=0;
        int index2=0;
        while(index1<str1.size()&&index2<str2.size()){
            if(str2[index2]-str1[index1]==1 || str2[index2]-str1[index1]==0 || (str1[index1]=='z' && str2[index2]=='a')){index2++;index1++;}
            else{
                index1++;
            }
        }
        if(index2<str2.size())return false;
        return true;
    }
};