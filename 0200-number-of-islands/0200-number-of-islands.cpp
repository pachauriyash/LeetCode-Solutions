class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=delrow+row;
                    int ncol=delcol+col;
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m &&(nrow==row || ncol==col) && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    ans++;
                    bfs(row,col,grid,vis);
                }
            }
        }
        return ans;
    }
};