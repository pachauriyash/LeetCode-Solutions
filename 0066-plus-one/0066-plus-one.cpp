class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans=digits;
        int carry=0,n=digits.size();
        ans[n-1]=(digits[n-1]+1+carry)%10;
        carry=(digits[n-1]+1+carry)/10;
        for(int i=n-2;i>=0;i--){
            ans[i]=(digits[i]+carry)%10;
            carry=(digits[i]+carry)/10;
        }
        if(carry!=0){
            ans.insert(ans.begin(),carry);
        }
        return ans;

    }
};