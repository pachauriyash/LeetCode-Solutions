class Solution {
public:
    // void recur(int index,string &temp,int &len,string&s,map<char,int>&mp,string&ans){
    //     if(index==s.size()){
    //         if(temp.size()==len){
    //             if(temp<ans){ans=temp;}
    //         }
    //         return;
    //     }
    //     if(s.size()-index>=len-temp.size()){
    //         recur(index+1,temp,len,s,mp,ans);
    //     }
    //     if(temp.length()<len){
    //         if(mp.find(s[index])==mp.end()){
    //             mp[s[index]]++;
    //             temp=temp+s[index];
    //             recur(index+1,temp,len,s,mp,ans);
    //             temp=temp.substr(0,temp.size()-1);
    //             mp[s[index]]--;
    //             if(mp[s[index]]==0)mp.erase(s[index]);
    //         }
            
    //     }
        
    // }
    string removeDuplicateLetters(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        // int len=mp.size();
        // mp.clear();
        // set<string>st;
        // string temp="";
        // string ans="";
        // for(int i=0;i<len;i++)ans+='z';
        // recur(0,temp,len,s,mp,ans);
        // return ans;

        //optimised approach
        vector<int>vis(26,0);
        string ans="";
        for(int i=0;i<s.size();i++){
            mp[s[i]]--;
            if(!vis[s[i]-'a']){
                while(ans.size()>0 && ans.back()>s[i] && mp[ans.back()]>0){
                 vis[ans.back()-'a']=0;
                 ans.pop_back();   
                }
                vis[s[i]-'a']=1;
                ans+=s[i];
            }
        }
        return ans;
    }
};