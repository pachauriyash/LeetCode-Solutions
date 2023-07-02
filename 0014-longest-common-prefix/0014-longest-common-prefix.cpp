class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index=0;
        string temp="";
        bool valid=true;
        while(index<strs[0].length()){
            for(int i=1;i<strs.size();i++){
                if(index>strs[i].size()){valid=false;break;}
                if(strs[i][index]!=strs[0][index]){valid=false;break;}
            }
            if(valid==false){break;}
            else{temp+=strs[0][index];index++;}
        }
        return temp;
    }
};