class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        string ans="";
        int carry=0;
        while(i>=0 && j>=0){
            long sum=int(num1[i]-'0')+int(num2[j]-'0')+carry;
            if(sum>9){carry=1;sum-=10;}
            else{carry=0;}
            ans+=char(sum)+'0';
            i--;
            j--;
        }
        if(i>=0){
            while(i>=0){
                long sum=int(num1[i]-'0')+carry;
                if(sum>9){carry=1;sum-=10;}
                else{carry=0;}
                ans+=char(sum+'0');
                i--;
            }
        }
        if(j>=0){
            while(j>=0){
                long sum=int(num2[j]-'0')+carry;
                if(sum>9){carry=1;sum-=10;}
                else{carry=0;}
                ans+=char(sum+'0');
                j--;
            }
        }
        if(carry==1){ans+='1';}
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};