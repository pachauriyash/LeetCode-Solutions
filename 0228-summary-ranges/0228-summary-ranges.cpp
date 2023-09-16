class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.size()==0)return ans;
        int start=nums[0];
        int end=nums[0];

        for(int i=1;i<nums.size();i++){
            
            if(((nums[i]<=0 && nums[i-1]<=0) || (nums[i]>=0 && nums[i-1]>=0)) && abs(nums[i]-nums[i-1])>1){
                string temp="";
                if(start==end){
                    temp+=to_string(start);
                }else{
                    temp+=to_string(start)+"->"+to_string(end);
                }
                ans.push_back(temp);
                start=nums[i];
                end=nums[i];
            }
            else if((nums[i]<0 && nums[i-1]>0)||(nums[i]>0 && nums[i-1]<0)){
                string temp="";
                if(start==end){
                    temp+=to_string(start);
                }else{
                    temp+=to_string(start)+"->"+to_string(end);
                }
                ans.push_back(temp);
                start=nums[i];
                end=nums[i];
            }
            else{
                end=nums[i];
            }
        }
        string temp="";
        if(start==end){
            temp+=to_string(start);
        }else{
            temp+=to_string(start)+"->"+to_string(end);
        }
        
        ans.push_back(temp);
        return ans;
    }
};