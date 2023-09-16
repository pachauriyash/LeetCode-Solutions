class Solution {
public:
    bool static comp(vector<int>&p1,vector<int>&p2){
        return p1[1]<p2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int end=points[0][1];
        int count=1;
        for(int i=1;i<points.size();i++){
            //cout<<points[i][0]<<" "<<points[i][1]<<" : ";
            if(points[i][0]>end){
                count++;
                end=points[i][1];
            }
        }
        return count;

    }
};