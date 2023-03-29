class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
	int cols = matrix[0].size();
        bool ans=false;
        int temp=0;
    for(int i=0;i<rows;i++){
        if(matrix[i][cols-1]>=target){temp=i;break;}
        
    }
    for(int j=0;j<cols;j++){
        if(matrix[temp][j]==target){ans=true;}
    }
        //if(temp==0){return true;}
        return ans;
    }
};