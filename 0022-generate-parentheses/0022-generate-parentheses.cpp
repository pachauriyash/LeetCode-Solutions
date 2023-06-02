class Solution {
public:
   void gps(vector<string> &ans,string s, int open,int close){
       if(open==0 && close==0){
           ans.push_back(s);
           return;
       }
       if(open>0){
           gps(ans,s+'(',open-1,close);
       }
       if(close>open){
           gps(ans,s+')',open,close-1);
       }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        int open=n;
        int close=n;
        gps(ans,s,open,close);
        return ans;
    }
};