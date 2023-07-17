class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        //tabulation TC O(N*M) SC O(N*M)
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
        //if(text1[0]==text2[0]){dp[0][0]=1;}
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1]){dp[i][j]=1+dp[i-1][j-1];}
                else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
            }
        }
        int i=text1.length();
		int j=text2.length();
		string ans="";
		while(i>0 && j>0){
			if(text1[i-1]==text2[j-1]){
				ans+=text1[i-1];
				i--;j--;
			}
			else if(dp[i-1][j]>dp[i][j-1]){
                ans+=text1[i-1];
				i--;
			}
			else {
                ans+=text2[j-1];
                j--;
            }
		}
		while(i>0){ans+=text1[i-1];i--;}
        while(j>0){ans+=text2[j-1];j--;}
       // cout<<ans;
         reverse(ans.begin(),ans.end());
        return ans;
    }
};