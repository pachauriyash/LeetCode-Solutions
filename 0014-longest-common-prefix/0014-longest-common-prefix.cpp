class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // bruteforce solution TC O(strs[0].size()*strs.size())
        //int index=0;
        // string temp="";
        // bool valid=true;
        // while(index<strs[0].length()){
        //     for(int i=1;i<strs.size();i++){
        //         if(index>strs[i].size()){valid=false;break;}
        //         if(strs[i][index]!=strs[0][index]){valid=false;break;}
        //     }
        //     if(valid==false){break;}
        //     else{temp+=strs[0][index];index++;}
        // }
        // return temp;
        
        //optimisez solution using lexographical order
        string ans="";
        sort(strs.begin(),strs.end());
        //now just check for first and last
        string first=strs[0],last=strs[strs.size()-1];
        for(int i=0;i<min(first.length(),last.length());i++){
            if(first[i]!=last[i])return ans;
            ans+=first[i];
        }
        return ans;
    }
};