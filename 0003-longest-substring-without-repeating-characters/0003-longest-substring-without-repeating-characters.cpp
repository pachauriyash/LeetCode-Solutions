class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int ans=0;
        // for(int i=0;i<s.length();i++){
        //     map<char,int>mp;
        //     int temp=0;
        //     for(int j=i;j<s.length();j++){
        //         if(mp.find(s[j])==mp.end()){
        //             mp[s[j]]++;
        //             temp++;
        //         }
        //         else{
        //             ans=max(ans,temp);
        //             break;
        //         }
        //     }
        //     ans=max(ans,temp);
        // }
        // return ans;
        //2 pointer approach  O(2N) SC O(N)
//         unordered_set<char>mp;
//         int ans=0;
//         int l=0;
//         int r=0;
//         while(r<s.length()){
//             if(mp.find(s[r])!=mp.end()){
//                 mp.erase(s[l]);
//                 l++;
//             }
//             else{
//                 mp.insert(s[r]);
//                 ans=max(ans,r-l+1);
//                 r++;
                
//             }
//         }
//         return ans;
        map<char,int>mp;
        int ans=0;
        int l=0;
        int r=0;
        while(r<s.length()){
            if(mp.find(s[r])!=mp.end()){
                
                if(mp[s[r]]>=l){
                    l=mp[s[r]]+1;
                }
                mp[s[r]]=r;
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                mp.insert({s[r],r});
                ans=max(ans,r-l+1);
                r++;
                
            }
        }
        return ans;
        
    }
};