class Solution {
public:
    string reverseWords(string s) {
        //first remove the spaces from beginning and end
        int size=s.length();
        int i=0,j=size-1;
        while(i<size && s[i]==' ')i++;
        while(j>0 && s[j]==' ')j--;
        s=s.substr(i,j-i+1);
        s=" "+s;
        int count=1;
        int k=s.length()-1;
        string temp="";
        
        while(k>=0){

            if(s[k]==' ' && count!=0){
                temp+=s.substr(k+1,count)+" ";
                //cout<<count;
                count=0;
            }
            else if(s[k]!=' ')count++;
            k--;
        }
        return temp.substr(0,temp.length()-1);
    }
};