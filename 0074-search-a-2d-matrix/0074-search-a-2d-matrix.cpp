class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /* this approach tc is O(n+m)
        for(int i=1;i<matrix.size();i++){
            if(target<matrix[i][0] && target>=matrix[i-1][0]){
                for(int j=0;j<matrix[0].size();j++){
                    if(matrix[i-1][j]==target){return true;}
                }
                return false;
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[matrix.size()-1][i]==target){return true;}
        }
        return false;
        */
        //best approach is using binary search which has tc as O(log(m*n))
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0){return false;}
        int low=0;int high=m*n-1;
        while(low<=high){
            int mid= (low+(high-low)/2);
            if(matrix[mid/m][mid%m]==target){return true;}
            if(matrix[mid/m][mid%m]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};