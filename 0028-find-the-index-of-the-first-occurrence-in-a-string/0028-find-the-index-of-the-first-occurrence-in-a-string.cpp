class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=-1;
        vector<int> v;
           for(int j=0;j<haystack.size();j++){
               if(needle[0]==haystack[j]){v.push_back(j);}
           }
        for(int k=0;k<v.size();k++){
            int j=v[k];
            if(haystack.size()-j<needle.size()){return -1;}
            for(int i=0;i<needle.size();i++){
                if(needle[i]==haystack[j+i] ){ans=j;}
                else{ans=-1;break;}
            }
            if(ans!=-1){break;}
        }
        
        return ans;
    }
};