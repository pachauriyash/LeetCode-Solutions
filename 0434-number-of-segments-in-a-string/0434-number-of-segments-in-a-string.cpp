class Solution {
public:
    int countSegments(string s) {
        int size=s.size();
        if(size==0){return 0;}
        int count=1;
        int temp=0;
        for(int i=0;i<size;i++){
            if(s[i]==' ' && i!=size-1 && i!=0 && s[i-1]!=' '){count++;}
            if(s[i]!=' '){temp++;}
        }
        if(temp==0 && count!=0){return 0;}
        if(s[size-1]==' ' && s[size-2]==' '){count--;}
        return count;
    }
};