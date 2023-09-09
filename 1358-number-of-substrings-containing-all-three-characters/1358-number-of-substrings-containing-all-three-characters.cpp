class Solution {
public:
    int fun(string s){
        map<char,int>mp;
        int i=0,j=0;
        int count=0;
        while(j<s.length()){
            mp[s[j]]++;
            while(i<=j && mp.size()>=3){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        //so basically out of all non empty substring subtract all non empty substring which contain less than 3 distinct characters(a,b,c) so what will be left is containing all three characters
        //return s.size()*(s.size()+1)/2 -fun(s);
        
        //another solution straight away
        int i=0,j=0,ans=0;
        int count[3]={0,0,0};
        while(j<s.length()){
            count[s[j]-'a']++;
            while(count[0]>0 && count[1]>0 && count[2]>0){
                count[s[i]-'a']--;
                i++;
            }
            ans+=i;
            j++;
        }
        return ans;
    }
};