class Solution {
public:
    bool isValid(string s) {
        bool ans=false;
        stack <char> stac;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
               stac.push(s[i]); 
            }
            else{
                if(!stac.empty()){
                    char temp=stac.top();
                    if(s[i]==')' && temp=='('){stac.pop();}
                    else{
                        stac.push(s[i]);
                    }
                }
                else{
                    stac.push(s[i]);
                }
            }
        }
        if(stac.empty()){ans=true;}
        if(!stac.empty()){ans=false;}
        return ans;
    }
    void gps(vector<string> &ans,string s, int n){
        if(n==0){
            if(isValid(s)){ans.push_back(s);}
            return;
        }
        
        gps(ans,s+'(',n-1);
        gps(ans,s+')',n-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        gps(ans,s,2*n);
        return ans;
    }
};