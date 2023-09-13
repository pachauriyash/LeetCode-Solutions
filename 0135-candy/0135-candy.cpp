class Solution {
public:
    int candy(vector<int>& rating) {
        vector<int>vt(rating.size(),1);
        for(int i=1;i<rating.size();i++){
            if(rating[i-1]<rating[i]){
                vt[i]=vt[i-1]+1;
            }
        }
        for(int i=rating.size()-1;i>0;i--){
            if(rating[i]<rating[i-1]){
                vt[i-1]=max(vt[i-1],vt[i]+1);
            }
        }
        int ans=0;
        for(auto it:vt){
            ans+=it;
        }
        return ans;
    }
};