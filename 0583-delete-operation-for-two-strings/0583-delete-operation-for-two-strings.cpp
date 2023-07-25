class Solution {
public:
    int minDistance(string text1, string text2) {
        //space optimised LCS
        vector<int>prev(text2.length()+1,0),curr(text2.length()+1,0);
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1]){curr[j]=1+prev[j-1];}
                else{curr[j]=max(prev[j],curr[j-1]);}
            }
            prev=curr;
        }
        return text1.length()+text2.length()- 2*prev[text2.length()];
    }
};