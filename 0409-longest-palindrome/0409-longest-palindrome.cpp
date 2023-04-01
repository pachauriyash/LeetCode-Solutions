class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        if(s.empty()){return 0;}
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=1;
            }
            else{
                mp[s[i]]+=1;
            }
        }
        int temp=0;
        int size=mp.size();
        if(size==1){return s.size();}
        int count=0;
        for(auto p:mp){
            if(p.second==1){temp++;}
            else if(p.second%2==0){ans+=p.second;}
            else{ans+=p.second-1;count++;}
        }
        //if(temp!=0){ans+=1;}
        if(temp==0 && count==0){return ans;}
        ans+=1;
        return ans;
    }
};