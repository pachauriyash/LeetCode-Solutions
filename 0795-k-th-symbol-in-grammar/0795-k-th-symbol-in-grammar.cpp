class Solution {
public:
    int kthGrammar(int n, int k) {
        //cout<<n<<":"<<k<<" ";
        if(n==1){
            if(k==1)return 0;
            else return 1;
        }
        int temp=pow(2,n);
        if(k>temp/2){
            // (((temp/4)+k%(temp/2))%(temp/2))+1
            int t=(k%(temp/2)+(temp/4));
            if(t>(temp/2)){
                return kthGrammar(n-1,t%(temp/2));
            }
            else{
               return kthGrammar(n-1,t);
            }
            
        }else{
            return kthGrammar(n-1,k);
        }
    }
};