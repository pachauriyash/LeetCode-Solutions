class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int temp=sqrt(i*i+j*j);
                
                if(temp*temp==i*i+j*j && temp<=n){
                    ans++;
                    cout<<i<<" "<<j<<" ";
                                    }
            }
        }
        return ans*2;
    }
};