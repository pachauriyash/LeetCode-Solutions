class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int temp=0;
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=0;i<g.size();i++){
            for(int j=temp;j<s.size();j++){
                if(s[j]>=g[i]){
                    count++;
                    temp=j+1; 
                    break;
                }
            }
        }
        return count;
    }
};