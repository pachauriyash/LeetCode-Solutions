class Solution {
public:
    string reverseWords(string s) {
        int prev=0;
        s=" "+s;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(s.begin()+prev,s.begin()+i);
                prev=i;
            }   
        }
        reverse(s.begin()+prev,s.end());
        s.pop_back();
        return s;
    }
};