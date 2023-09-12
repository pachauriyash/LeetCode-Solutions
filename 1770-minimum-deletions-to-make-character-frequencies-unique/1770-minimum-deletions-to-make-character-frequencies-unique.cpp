class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(auto it:s)freq[it-'a']++;
        sort(freq.begin(),freq.end(),greater<int>());
        int ans=0;
        for(int i=1;i<freq.size();i++){
            if(freq[i]==freq[i-1] && freq[i]!=0){
                freq[i]--;
                ans++;
                i--;
                sort(freq.begin(),freq.end(),greater<int>());
            }
        }
        return ans;
    }
};