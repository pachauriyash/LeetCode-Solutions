class Solution {
public:
    bool rotateString(string s, string goal) {
        int size=s.size();
        int count=size-1;
        if(s==goal){return true;}
        if(size!=goal.size()){return false;}
        while(count>0){
            char temp=s[0];
            for(int i=0;i<size-1;i++){
                s[i]=s[i+1];
            }
            s[size-1]=temp;
            if(s==goal){return true;}
            count--;
        }
        return false;
    }
};