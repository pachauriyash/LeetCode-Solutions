class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> v1;
        vector<int> v2;
        vector<vector<int>> ans;
        v1.push_back(1);
        ans.push_back(v1);
        v1.clear();
        v1.push_back(1);
        v1.push_back(1);
        if(numRows==1){return ans;}
        ans.push_back(v1);
        while(numRows>2){
            v2.push_back(v1[0]);
            for(int i=0;i<v1.size()-1;i++){
                int temp=v1[i]+v1[i+1];
                v2.push_back(temp);
            }
            v2.push_back(v1[v1.size()-1]);
            v1.clear();
            v1=v2;
            ans.push_back(v2);
            v2.clear();
            numRows--;
        }
        return ans;
    }
};