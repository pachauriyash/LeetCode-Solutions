class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int row=0,col=0;
        long long ans=0;
        vector<bool> rowFlag(n, 1), colFlag(n, 1);
        for(int i=queries.size()-1;i>=0;i--){
            int index=queries[i][1];
            int val=queries[i][2];
            if(queries[i][0]==0 && rowFlag[index]){
                ans+=val*(n-col);
                row++;
                rowFlag[index]=0;
            }
            if(queries[i][0]==1 && colFlag[index]){
                ans+=val*(n-row);
                col++;
                colFlag[index]=0;
            }
            }
        
        
        return ans;
    }
};