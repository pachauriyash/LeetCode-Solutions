class Solution {
public:
    vector<string> fizzBuzz(int n) {
    vector<string> ans;
        for(int i=0;i<n;i++){
            string temp="";
            if((i+1)%3==0 && (i+1)%5==0){temp="FizzBuzz";}
            else if((i+1)%3==0){temp="Fizz";}
            else if((i+1)%5==0){temp="Buzz";}
            else{
                temp=to_string(i+1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};