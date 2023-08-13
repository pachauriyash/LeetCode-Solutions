class Solution {
public:
    bool halvesAreAlike(string s) {
        int vowel1=0,vowel2=0;
        int cons1=0,cons2=0;
        int n=s.length()/2;
        for(int i=0;i<s.length()/2;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u' || s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')vowel1++;
            else{cons1++;}
            if(s[i+n]=='a'||s[i+n]=='e'||s[i+n]=='i'||s[i+n]=='o'||s[i+n]=='u' || s[i+n]=='A'||s[i+n]=='E'||s[i+n]=='I'||s[i+n]=='O'||s[i+n]=='U')vowel2++;
            else{cons2++;}
        }
        return (vowel1==vowel2)&&(cons1==cons2);
    }
};