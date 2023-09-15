class Solution {
public:
    int alive(vector<vector<int>>& board,int row,int col){
        int delrow[]={-1,-1,0,+1,+1,+1,0,-1};
        int delcol[]={0,+1,+1,+1,0,-1,-1,-1};
        int count=0;
        for(int i=0;i<8;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size()){
                if(board[nrow][ncol]==1 || board[nrow][ncol]==2)count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        //vector<vector<int>>temp(board.size(),vector<int>(board[0].size()));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int count=alive(board,i,j);
                if(board[i][j]==1){
                    if(count<2 || count>3){board[i][j]=2;}

                }else{
                    if(count==3){board[i][j]=3;}

                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]==2){
                   board[i][j]=0;

                }
                if(board[i][j]==3){
                    board[i][j]=1;
                }
            }
        }

    }
};