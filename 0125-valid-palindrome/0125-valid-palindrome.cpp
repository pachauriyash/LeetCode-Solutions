class Solution {
public:
    bool notval(int t){
        if((t<65 || (t>90 && t<97) || t>122) && !(t>47 && t<58)){return true;}
        return false;
    }
    int lower(int t){
        if(t>=65 && t<=90){
                return t+32;
            }
        else{return t;}
        return 0;
    }
    bool isPalindrome(string s) {
        /*string temp="";
        for(int i=0;i<s.size();i++){
            if((int(s[i])<65 || (int(s[i])>90 && int(s[i])<97) || int(s[i])>122) && !(int(s[i])>47 && int(s[i])<58)){continue;}
            if(int(s[i])>=65 && int(s[i])<=90){
                char t=char(int(s[i])+32);
                string tt(1,t);
                temp=temp+tt;
            }
            else{temp+=s[i];}
        }
        int j=temp.size()-1;
        int ans=true;
        for(int i=0;i<j;i++){
            if(temp[i]!=temp[j]){ans=false;}
            j--;
        } */
        bool ans=true;
        int right=s.size()-1;
        int left=0;
         while(left<right)
        {
            if(notval(s[left])) left++;
            else if(notval(s[right])) right--;
            else if(lower(s[left])!=lower(s[right])) return false;
            else {left++; right--;}
        }
        return ans;
    }
};