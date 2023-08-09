class Solution {
public:
    string makeFancyString(string s) {
        int size=s.size();
        if(size<3)return s;
        int i=0,j=1,k=2;
        string ans="";
        while(k!=s.size()){
            if(s[i]==s[j] &&s[j]==s[k]){
                // s.erase(s.begin()+k);
                i++;j++;k++;
            }
            else{
                ans+=s[i];
                i++;j++;k++;
            }
        }
        ans+=s[j-1];
        ans+=s[k-1];
        // for(i=0,j=1,k=2;i<s.size()-2,j<s.size()-1,k<s.size();i++,j++,k++){
        //     if(s[i]==s[j] &&s[j]==s[k]){s.erase(s.begin()+k);}
        // }
        return ans;
    }
};