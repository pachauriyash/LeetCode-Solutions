class Solution {
public:
    bool recur(vector<vector<char>>& board,int row,int col,string &temp,string &word,vector<vector<char>>&visited){
        if(temp.size()==word.size()){
            return temp==word;
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        bool ans=false;
        for(int i=0;i<4;i++){
            int newrow=row+delrow[i];
            int newcol=col+delcol[i];
            if(newrow<board.size() && newrow>=0 && newcol<board[0].size() && newcol>=0 &&visited[newrow][newcol]!=1){
                visited[newrow][newcol]=1;
                temp.push_back(board[newrow][newcol]);
                ans= ans || recur(board,newrow,newcol,temp,word,visited);
                visited[newrow][newcol]=0;
                temp.pop_back();
            }
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    string temp="";
                    temp+=word[0];
                    vector<vector<char>>visited(board.size(),vector<char>(board[0].size(),0));
                    visited[i][j]=1;
                    ans=ans || recur(board,i,j,temp,word,visited);
                    if(ans==true)return ans;
                }
            }
        }
        return ans;
    }
};