class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int index=0;
        int start=intervals[0][0];
        int end=intervals[0][1];
        //vector<int> temp;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
                ans[index][0]=min(intervals[i][0],start);
                ans[index][1]=max(intervals[i][1],end);
                start=ans[index][0];
                end=ans[index][1];
            }
            else{
                //vector<int> temp;
                // temp.push_back(intervals[i][0]);
                // temp.push_back(intervals[i][1]);
                
                ans.push_back(intervals[i]);
                index++;
                start=ans[index][0];
                end=ans[index][1];
            }
        }
        return ans;
    }
};