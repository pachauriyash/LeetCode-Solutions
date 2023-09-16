class Solution {
public:
    string givestring(int n){
        if(n==2)return "abc";
        if(n==3)return "def";
        if(n==4)return "ghi";
        if(n==5)return "jkl";
        if(n==6)return "mno";
        if(n==7)return "pqrs";
        if(n==8)return "tuv";
        return "wxyz";
    }
    void recur(string digits,int index,string&temp,vector<string>&ans){
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        string tempstring=givestring(digits[index]-'0');
        for(int i=0;i<tempstring.size();i++){
            temp+=tempstring[i];
            recur(digits,index+1,temp,ans);
            temp=temp.substr(0,temp.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp="";
        vector<string>ans;
        if(digits.size()==0)return ans;
        recur(digits,0,temp,ans);
        return ans;
    }
};