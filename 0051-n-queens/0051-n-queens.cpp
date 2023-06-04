class Solution {
public:
    /*
    bool issafe(int row, int col, vector<string> board,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){return false;}
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0){
            if(board[row][col]=='Q'){return false;}
            col--;
        }
        col=dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){return false;}
            row++;
            col--;
        }
        return true;
    }
    void recur(vector<vector<string>>&ans,vector<string> &board,int col,int n){
        //base case
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n)){
                board[row][col]='Q';
                recur(ans,board,col+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        recur(ans,board,0,n);
        return ans;
    } */
    //better time complexity by using hashing
    void recur(vector<vector<string>>&ans,vector<string> &board,int col,int n,vector<int> &leftrow,vector<int> &upperdiag,vector<int> &lowerdiag){
        //base case
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerdiag[row+col]==0 && upperdiag[n-1+col-row]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                upperdiag[n-1+col-row]=1;
                lowerdiag[row+col]=1;
                recur(ans,board,col+1,n,leftrow,upperdiag,lowerdiag);
                board[row][col]='.';
                leftrow[row]=0;
                upperdiag[n-1+col-row]=0;
                lowerdiag[row+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> leftrow(n,0),upperdiag(2*n-1,0),lowerdiag(2*n-1,0);
        recur(ans,board,0,n,leftrow,upperdiag,lowerdiag);
        return ans;
    }
};