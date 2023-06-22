class Solution {
public:
    //simply this can be done using recursion but you get tle so to solve it using a dp hash table
    int recur(int m, int n, int row,int col,vector<vector<int>>&dphash){
        if(row>=m || col>=n){return 0;}
        if(row==m-1 && col==n-1){return 1;}
        if(dphash[row][col]!=-1){
            return dphash[row][col];
        }
        return dphash[row][col]= recur(m,n,row+1,col,dphash) +recur(m,n,row,col+1,dphash);
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dphash(m,vector<int>(n,-1));
        return recur(m,n,0,0,dphash);
    }
};