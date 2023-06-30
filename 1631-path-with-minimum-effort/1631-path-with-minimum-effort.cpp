class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
       //{diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> qq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        qq.push({0,{0,0}});
        int rowposs[]={-1,0,+1,0};
        int colposs[]={0,+1,0,-1};
        while(!qq.empty()){
            auto it=qq.top();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            qq.pop();
            if(row==n-1 && col==m-1){return diff;}
            for(int i=0;i<4;i++){
                int newrow=row+rowposs[i];
                int newcol=col+colposs[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m){
                    int neweffort=max(abs(grid[newrow][newcol]-grid[row][col]),diff);
                    if(neweffort<dist[newrow][newcol]){
                        dist[newrow][newcol]=neweffort;
                        qq.push({neweffort,{newrow,newcol}});
                    }    
                }

            }
        }
        
        return dist[n-1][m-1];
        
    }
};