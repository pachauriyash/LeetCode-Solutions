class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=INT_MIN;
        for(int i=0;i<points.size();i++){
            map<double,int>mp;
            int tempans=0;
            for(int j=i+1;j<points.size();j++){
                int xdiff=(points[j][0]-points[i][0]);
                double angle=INT_MAX;
                if(xdiff!=0){angle=(points[j][1]-points[i][1])/(double)xdiff;}
                mp[angle]++;
                tempans=max(tempans,mp[angle]);
            }
            tempans++;
            ans=max(ans,tempans);
        }
        return ans;
    }
};