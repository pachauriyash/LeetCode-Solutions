class Solution {
public:
    bool ispalindrome(string s,int start,int end){
        int i=start,j=end;
        while(i<=j){
            if(s[i]!=s[j]){return false;}
            i++;
            j--;
        }
        return true;
    }
    void recur(vector<vector<string>>&ans,string s,int index,vector<string>&temp){
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(ispalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                recur(ans,s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        recur(ans,s,0,temp);
        return ans;
    }
};