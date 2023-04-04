class Solution {
public:
    bool isinteger(char c){
        if(int(c)>=48 && int(c)<=57){return true;}
        return false;
    }
    string decodeString(string s) {
        //if(isinteger(s[0])){return "heelo";}
        stack<char> st;
        string ans="";
        string anns="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){st.push(s[i]);}
            else{
                string temp="";
                while(st.top()!='['){
                    string x=temp;
                    temp=st.top();
                    temp+=x;
                    st.pop();
                }
                st.pop();
                int count=0;
                int ten=1;
                while(isinteger(st.top())){
                    count+= ten*(int(st.top()-'0'));
                    ten=ten*10;
                    st.pop();
                    if(st.empty()){break;}
                }
                while(count>0){
                    ans+=temp;
                    count--;
                }
                if(!st.empty()){
                    for(int j=0;j<ans.size();j++){
                        st.push(ans[j]);
                    }
                    ans="";
                }
                else{
                    anns+=ans;
                    ans="";
                } 
            }
        }
        string t="";
        while(!st.empty()){
            string temp=t;
            t=st.top();
            t+=temp;
            st.pop();   
        }
        anns+=t;
        return anns;
    }
};