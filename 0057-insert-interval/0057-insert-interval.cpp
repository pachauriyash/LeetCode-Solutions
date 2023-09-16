class Solution {
public:
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(),intervals.end());
        
    //     vector<vector<int>> ans;
    //     ans.push_back(intervals[0]);
    //     int index=0;
    //     int start=intervals[0][0];
    //     int end=intervals[0][1];
    //     //vector<int> temp;
    //     for(int i=1;i<intervals.size();i++){
    //         if(intervals[i][0]<=end){
    //             ans[index][0]=min(intervals[i][0],start);
    //             ans[index][1]=max(intervals[i][1],end);
    //             start=ans[index][0];
    //             end=ans[index][1];
    //         }
    //         else{ 
    //             ans.push_back(intervals[i]);
    //             index++;
    //             start=ans[index][0];
    //             end=ans[index][1];
    //         }
    //     }
    //     return ans;
    // }
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     //one way to do is by using merge intervals and it'll take care of the new interval and merge it accordingly but that uses more space and time
    //     intervals.push_back(newInterval);
    //     vector<vector<int>>ans;
    //     ans=merge(intervals);
    //     return ans;
    // }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int start=newInterval[0];
        int end=newInterval[1];
        int index=0;
        for(int i=0;i<intervals.size();i++){
            if(end<intervals[i][0]){
                ans.push_back({start,end});
                start=INT_MAX;
                end=INT_MAX;
            }
            if(start!=INT_MAX && end!=INT_MAX && (end<=intervals[i][1]) ){
                start=min(intervals[i][0],start);
                end=max(intervals[i][1],end);
            }
            else if(start!=INT_MAX && end!=INT_MAX && (end>intervals[i][1] && start<=intervals[i][1]) ){
                start=min(intervals[i][0],start);
                end=max(intervals[i][1],end);
            }
            else{
                //cout<<"mujhe";
                ans.push_back(intervals[i]);
            }
        }
        if(start!=INT_MAX && end!=INT_MAX){
            ans.push_back({start,end});
        }
        return ans;

    }
};