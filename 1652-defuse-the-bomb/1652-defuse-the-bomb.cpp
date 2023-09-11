class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans;
       if(k>0){
           for(int i=0;i<code.size();i++){
               int temp=k;
               int index=i+1;
               int tempsum=0;
               while(temp>0){
                   tempsum+=code[index%code.size()];
                   index++;
                   temp--;
               }
               ans.push_back(tempsum);
           }
       }
        else if(k<0){
            for(int i=0;i<code.size();i++){
               int temp=abs(k);
               int index=i-1;
               int tempsum=0;
               while(temp>0){
                   tempsum+=code[(index+code.size())%code.size()];
                   index--;
                   temp--;
               }
               ans.push_back(tempsum);
           }
        }
        else{
            for(int i=0;i<code.size();i++){
               ans.push_back(0);
           }
        }
        return ans;
    }
};