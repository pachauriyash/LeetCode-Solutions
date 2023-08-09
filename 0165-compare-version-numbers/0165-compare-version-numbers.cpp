class Solution {
public:
    int compareVersion(string version1, string version2) {
        int prev1=0;
        int prev2=0;
        int ans=0;
        while(prev1<version1.length()&&prev2<version2.length()){
            while(version1[prev1]=='0'){
                prev1++;
                if(version1[prev1]=='.'||prev1==version1.length()){prev1--;break;}
            }
            
            while(version2[prev2]=='0'){
                prev2++;
                if(version2[prev2]=='.'||prev2==version2.length()){prev2--;break;}
            }
             cout<<prev1<<" "<<prev2<<" ";
            if(!(prev1<version1.length()&&prev2<version2.length())){break;}
            
            if((version1[prev1]=='.' && version2[prev2]!='.')){return -1;}
            else if((version2[prev2]=='.' && version1[prev1]!='.')){return 1;}
            else if(version1[prev1]<version2[prev2]){ans=-1;prev1++;prev2++;break;}
            else if(version1[prev1]>version2[prev2]){ans=1;prev1++;prev2++;break;}
            else{
                prev1++;prev2++;
            }
            // if(version1[prev1]==version2[prev2]){prev1++;prev2++;}
        }
        // cout<<prev1<<" "<<prev2<<" ";
        if(prev1!=version1.length() && prev2!=version2.length()){
            if(version1[prev1]=='.' && version2[prev2]!='.'){return -1;}
            else if(version2[prev2]=='.' && version1[prev1]!='.'){return 1;}
            else{return ans;}
        }
        if((prev1==version1.length() || prev2==version2.length()) && ans!=0){
            cout<<"balle";
            if(prev1==version1.length() && prev2!=version2.length() && version2[prev2]=='.'){
                return ans;
            }
            if(prev2==version2.length() && prev1!=version1.length() && version1[prev1]=='.'){
                            return ans;
            }

        }
        if(prev1!=version1.length()){
            if(version1[prev1]!='.')return 1;
            while(prev1<version1.length()){
                if(version1[prev1]!='.' && version1[prev1]!='0'){return 1;}
                prev1++;
            }
        }
        if(prev2!=version2.length()){
            if(version2[prev2]!='.')return -1;
             while(prev2<version2.length()){
                 // cout<<0<<" "<<prev2<<" ";
                 if(version2[prev2]!='.' && version2[prev2]!='0'){return -1;}
                prev2++;
             }
        }
        
        return ans;
    }
};