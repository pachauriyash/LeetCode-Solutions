class Solution {
public:
    int summ(int x,int y,int &carry){
        int z=carry;
        if(x==0 && y==0 && z==0){carry=0;return 0;}
        if(x==0 && y==0 && z==1){carry=0;return 1;}
        if(x==0 && y==1 && z==0){carry=0;return 1;}
        if(x==0 && y==1 && z==1){carry=1;return 0;}
        if(x==1 && y==0 && z==0){carry=0;return 1;}
        if(x==1 && y==0 && z==1){carry=1;return 0;}
        if(x==1 && y==1 && z==0){carry=1;return 0;}
        if(x==1 && y==1 && z==1){carry=1;return 1;}
        return 0;
    }
    
    string addBinary(string a, string b) {
        string ans="";
        if(a.size()<b.size()){ans=a;a=b;b=ans;ans="";}
        int j=b.size()-1;
        int carry=0;
        int y=0;
        
        for(int i=a.size()-1;i>=0;i--){
            if(j>=0){y=int(b[j]-'0');}
            else{y=0;}
            j--;
            int x=int(a[i]-'0');
            int t=summ(x,y,carry);
            if(t==1){ans=ans.append("1");}
            if(t==0){ans=ans.append("0");}
        }
        if(carry==1){ans=ans.append("1");}
        reverse(ans.begin(), ans.end());
        return ans;
    }
};