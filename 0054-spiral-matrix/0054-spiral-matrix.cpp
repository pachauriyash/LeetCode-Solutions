class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int flag=0,count=matrix.size()*matrix[0].size();
        int spiralcount=0,row=0,col=0;
        vector<int>ans;
        while(count>0){
            if(flag==0){
                ans.push_back(matrix[row][col]);
                col++;
                if(col==matrix[0].size()-spiralcount){
                    flag=1;
                    row++;
                    col--;
                }
            }
            else if(flag==1){
                ans.push_back(matrix[row][col]);
                row++;
                if(row==matrix.size()-spiralcount){
                    flag=2;
                    col--;
                    row--;
                }
            }
            else if(flag==2){
                ans.push_back(matrix[row][col]);
                col--;
                if(col==spiralcount-1){
                    flag=3;
                    col++;
                    row--;
                }
            }
            else{
                ans.push_back(matrix[row][col]);
                row--;
                if(row==spiralcount){
                    flag=0;
                    col++;
                    row++;
                    spiralcount++;
                }
            }
            count--;
        }
        return ans;
    }
};