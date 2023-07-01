class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row=0,col=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    row=i;
                    col=j;
                    break;
                }
            }
            if(board[row][col]=='R')break;
        }
        int count=0;
 
        //right side
        for(int k=col;k<8;k++){
            if(board[row][k]=='B'){break;}
            else if(board[row][k]=='p'){count++;break;}
        }

        //left side
        for(int k=col;k>=0;k--){
            if(board[row][k]=='B'){break;}
            else if(board[row][k]=='p'){count++;break;}
        }
        
        //upper
        for(int k=row;k<8;k++){
            if(board[k][col]=='B'){break;}
            else if(board[k][col]=='p'){count++;break;}
        }
        
        //bottom
        for(int k=row;k>=0;k--){
            if(board[k][col]=='B'){break;}
           else if(board[k][col]=='p'){count++;break;}
        }
        return count;
    }
};