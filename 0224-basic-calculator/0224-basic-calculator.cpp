class Solution {
public:
    int calculate(string s) {
        char prev='.';
        int index=0;
        while(index<s.size()&& s[index]==' ')index++;
        if(s[index]=='-'){
            s="0"+s.substr(index,s.size()-index);
        }
        stack<char>ope;
        stack<int>num;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')continue;
            if(s[i]<='9' && s[i]>='0'){
                int nums=0;
                while(i<s.size() && (s[i]<='9' && s[i]>='0')){
                    nums=nums*10+(s[i]-'0');
                    i++;
                }
                i--;
                //cout<<nums<<" ";
                num.push(nums);
                prev=s[i];
            }
            else if(s[i]==')'){
                while(ope.top()!='('){
                    int t1=num.top();
                    num.pop();
                    char op=ope.top();
                    ope.pop();
                    int t2=num.top();
                    num.pop();
                    if(ope.top()=='-'){
                        t2*=-1;
                        ope.pop();
                        ope.push('+');
                    }
                    int calc=0;
                    if(op=='+'){
                        calc=t1+t2;
                    }else{
                        calc=t2-t1;
                    }
                    if(ope.top()=='('){
                        ope.pop();
                        num.push(calc);
                        break;
                    }else{
                        num.push(calc);
                        if(ope.empty())break;
                    }
                }
                if(!ope.empty() && ope.top()=='(')ope.pop();
                cout<<num.top();
            }else{
                if(prev=='(' && s[i]=='-'){num.push(0);}
                ope.push(s[i]);
                prev=s[i];
            }
        }
        // cout<<ope.size()<<" "<<num.size()<<"huku"<<ope.top()<<num.top();
        while(!ope.empty()){
            int t1=num.top();
            num.pop();
            char op=ope.top();
            ope.pop();
            int t2=num.top();
            num.pop();
            if(!ope.empty() && ope.top()=='-'){
                t2*=-1;
                ope.pop();
                ope.push('+');
            }
            int calc=0;
            if(op=='+'){
                calc=t1+t2;
            }else{
                calc=t2-t1;
            }
            num.push(calc);
        }
        return num.top();
    }
};