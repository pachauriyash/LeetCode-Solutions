class Solution {
public:
    int firstUniqChar(string s) {
        /*queue<char>q;
        vector<char>qq;
        for(int i=0;i<s.size();i++){
            bool ans=true;
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]){
                    ans=false;
                    break;
                    }
            }
            for(int k=0;k<qq.size();k++){
                if(s[i]==qq[k]){ans=false;break;}
            }
            qq.push_back(s[i]);
            if(ans==true){q.push(i);};
        }
        if(q.empty()){return -1;}
        else{return q.front();} */
        int arr[26]={};
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        for(int j=0;j<s.size();j++){
            if(arr[s[j]-'a']==1){
                return j;
            }
        }
        return -1;
    }
};