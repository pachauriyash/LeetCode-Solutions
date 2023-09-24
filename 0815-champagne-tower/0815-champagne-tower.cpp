class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>matrix;
        vector<double>temp(1,poured);
        matrix.push_back(temp);
        for(int i=0;i<=query_row;i++){
            vector<double>temp(i+2,0);
            for(int j=0;j<i+1;j++){
                if(matrix[i][j]>=1){
                    temp[j]+=(matrix[i][j]-1.0)/2.0;
                    temp[j+1]+=(matrix[i][j]-1.0)/2.0;
                    matrix[i][j]=1;
                }
            }
            matrix.push_back(temp);
        }
        return matrix[query_row][query_glass];
    }
};