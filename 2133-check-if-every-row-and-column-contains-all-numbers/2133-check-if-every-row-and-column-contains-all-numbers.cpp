class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_map<int,unordered_set<int>>mprow,mpcol;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mpcol[j].insert(matrix[i][j]);
                mprow[i].insert(matrix[i][j]);
            }
        }
        if(mprow.size()!=matrix.size())return false;
        if(mpcol.size()!=matrix.size())return false;
        for(auto it:mprow){
            if(it.second.size()!=matrix[0].size())return false;
        }
        for(auto it:mpcol){
            if(it.second.size()!=matrix.size())return false;
        }
        return true;
    }
};