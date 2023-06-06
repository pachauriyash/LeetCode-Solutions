class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        bool firstrow=false;
        bool firstcol=false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    if(i==0){firstrow=true;}
                    if(j==0){firstcol=true;}
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<rows;i++){
            if(firstcol){
                matrix[i][0]=0;
            }
            
        }
        for(int i=0;i<cols;i++){
            if(firstrow){
                matrix[0][i]=0;
            }
            
        }
    }
};