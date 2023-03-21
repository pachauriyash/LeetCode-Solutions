class Solution {
public:
    bool isoperator(string s){
        if(s=="+" || s=="-" || s=="*" || s=="/"){return true;}
        else{return false;}
    }
    int calcul(int i1,int i2,string s){
        if(s=="+"){
            return (i1+i2);
        }
        else if(s=="-"){
            return (i1-i2);
        }
        else if(s=="*"){
            return (i1*i2);
        }
        else if(s=="/"){
            return (i1/i2);
        }
        else{return 0;}
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(!isoperator(tokens[i])){
                st.push(int(stoi(tokens[i])));
            }
            else{
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
                st.pop();
                int ans=calcul(temp2,temp1,tokens[i]);
                st.push(ans);
            } 
        }
        int t=st.top();
        st.pop();
        return t; 
    }
};