class Solution {
public:
    int recur(int i,int j1,int j2,int r,int c,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=c || j2<0 || j2>=c)return -1e8;
        if(i==r-1){
            if(j1==j2){return grid[i][j1];}
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int k=-1;k<=1;k++){
            for(int l=-1;l<=1;l++){
                int ans=0;
                if(j1==j2)ans=grid[i][j1];
                else ans=grid[i][j1]+grid[i][j2];
                ans+=recur(i+1,j1+k,j2+l,r,c,grid,dp);
                maxi=max(maxi,ans);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return recur(0,0,c-1,r,c,grid,dp);
    }
};