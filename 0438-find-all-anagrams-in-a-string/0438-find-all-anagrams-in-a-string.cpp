class Solution {
public:
    bool check(map<char,int>&mp1,map<char,int>&mp2){
        for(auto it:mp1){
            if(mp2.find(it.first)==mp2.end())return false;
            else{
                if(mp2[it.first]!=it.second)return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string txt, string pat) {
	    // int i=0,j=0;
	    // vector<int>ans;
	    // map<char,int>mp2,mp;
	    // int n=pat.size();
	    // for(int i=0;i<n;i++)mp2[pat[i]]++;
	    // while(j<txt.size()){
	    // mp[txt[j]]++;
	    // if(j-i+1==n){
	    // if(mp.size()==mp2.size() && check(mp,mp2)){
	    // ans.push_back(i);
	    // }
	    // mp[txt[i]]--;
	    // if(mp[txt[i]]==0)mp.erase(txt[i]);
	    // i++;
	    // j++;
	    // }
	    // else{
	    // j++;
	    // }
	    // }
	    // return ans;
        
        int i=0,j=0;
        int n=pat.size();
	    vector<int>ans;
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
	    for(int i=0;i<n;i++){
            freq_p[pat[i]-'a']++;
        }
        
        while(j<txt.size()){
	        window[txt[j]-'a']++;
	        if(j-i+1==n){
	            if(freq_p==window){
	                ans.push_back(i);
	            }
                window[txt[i]-'a']--;
	            i++;
	            j++;
	        }
	        else{
	            j++;
	        }
	    }
        return ans;
    }
};