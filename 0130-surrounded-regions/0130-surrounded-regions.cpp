class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>> &vis, vector<vector<char>> &board,int delrow[],int delcol[]){
        vis[row][col]=1;
        //top right bottom left
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<board.size() && ncol<board[0].size() && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,board,delrow,delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        //first row and last column
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,vis,board,delrow,delcol);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,vis,board,delrow,delcol);
            }
        }
        
        for(int j=0;j<n;j++){
            if(!vis[j][0] && board[j][0]=='O'){
                dfs(j,0,vis,board,delrow,delcol);
            }
            if(!vis[j][m-1] && board[j][m-1]=='O'){
                dfs(j,m-1,vis,board,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};