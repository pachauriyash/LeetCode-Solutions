class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len=cardPoints.size()-k;
        if(len==0)return accumulate(cardPoints.begin(),cardPoints.end(),0);
        int j=0,i=0;
        int tempsum=0,ans=INT_MAX;
        while(j<cardPoints.size()){
            tempsum+=cardPoints[j];
            if(j-i+1<len){j++;}
            else{
                ans=min(ans,tempsum);
                tempsum-=cardPoints[i];
                i++;
                j++;
            }
        }
        
        return accumulate(cardPoints.begin(),cardPoints.end(),0)-ans;
    }
};