class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
           vector<int>mapp(10,0); 
           for(int j=0;j<9;j++){
               if(board[i][j]=='.')continue;
               mapp[board[i][j]-'0']++;
               if(mapp[board[i][j]-'0']>1)return false;
           }
        }
        for(int i=0;i<9;i++){
           vector<int>mapp(10,0); 
           for(int j=0;j<9;j++){
               if(board[j][i]=='.')continue;
               mapp[board[j][i]-'0']++;
               if(mapp[board[j][i]-'0']>1)return false;
           }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<int>mapp(10,0); 
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]=='.')continue;
                        mapp[board[k][l]-'0']++;
                        if(mapp[board[k][l]-'0']>1)return false;
                    }
                }
            }
        }
        return true;
    }
};