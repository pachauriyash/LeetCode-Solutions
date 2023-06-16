class Solution {
    
public:
    void dfs(int row,int col,vector<vector<int>> &vis, vector<vector<int>> &board,int delrow[],int delcol[]){
        vis[row][col]=1;
        //top right bottom left
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<board.size() && ncol<board[0].size() && !vis[nrow][ncol] && board[nrow][ncol]==1){
                dfs(nrow,ncol,vis,board,delrow,delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
         vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]==1){
                dfs(0,i,vis,grid,delrow,delcol);
            }
            if(!vis[n-1][i] && grid[n-1][i]==1){
                dfs(n-1,i,vis,grid,delrow,delcol);
            }
        }
        
        for(int j=0;j<n;j++){
            if(!vis[j][0] && grid[j][0]==1){
                dfs(j,0,vis,grid,delrow,delcol);
            }
            if(!vis[j][m-1] && grid[j][m-1]==1){
                dfs(j,m-1,vis,grid,delrow,delcol);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};