class Solution {
public:
    bool isValid(string s) {
        bool ans=false;
        stack <char> stac;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
               stac.push(s[i]); 
            }
            else{
                if(!stac.empty()){
                    char temp=stac.top();
                    if((s[i]==')' && temp=='(') || (s[i]=='}' && temp=='{') ||                              (s[i]==']' && temp=='[')){stac.pop();}
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
};