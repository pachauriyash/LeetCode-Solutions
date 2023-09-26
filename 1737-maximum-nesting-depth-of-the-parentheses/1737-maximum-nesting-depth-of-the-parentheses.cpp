class Solution {
public:
    int maxDepth(string s) {
        int open=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')open++;
            if(s[i]==')')open--;
            ans=max(ans,open);
        }
        if(open!=0)return 0;
        return ans;
    }
};