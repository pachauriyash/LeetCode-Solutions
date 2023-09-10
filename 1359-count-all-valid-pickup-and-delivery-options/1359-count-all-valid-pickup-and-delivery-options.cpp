class Solution {
public:
    int recur(vector<int>&pick,vector<int>&delivery,int &n,vector<vector<int>>&dp){
        //base case
        if(pick.size()==0 && delivery.size()==0)return 1;
        if(dp[pick.size()][delivery.size()]!=-1)return dp[pick.size()][delivery.size()];
        int picked=0;
        if(pick.size()>0){
            for(int i=0;i<pick.size();i++){
                delivery.push_back(pick[i]);
                int val=pick[i];
                pick.erase(pick.begin()+i);
                picked=((picked)%1000000007+recur(pick,delivery,n,dp)%1000000007)%1000000007;
                pick.insert(pick.begin()+i,val);
                delivery.pop_back();
            }
        }
        int deli=0;
        for(int i=0;i<delivery.size();i++){
            int val=delivery[i];
            delivery.erase(delivery.begin()+i);
            deli= (deli%1000000007 + recur(pick,delivery,n,dp)%1000000007)%1000000007;
            delivery.insert(delivery.begin()+i,val);
        }
        //cout<<pick<<"<-pick:picked->"<<picked<<" "<<delivery.size()<<"<-deliverysize : delivered-> "<<deli;
        return dp[pick.size()][delivery.size()]=(picked%1000000007+deli%1000000007)%1000000007;
    }
    int countOrders(int n) {
        //passed only 21/36 test cases TLE from n=226
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // vector<int>delivery;
        // vector<int>pick;
        // for(int i=1;i<=n;i++)pick.push_back(i);
        // return recur(pick,delivery,n,dp);
        
        //it's maths basically and permutation and combination
        //first we insert all the pickups so n pickups permutations are n!
        //now comes delivery so here is a pattern
        //remember this 2*n-1
        // for nth pickup the only delivery possibility is 1, for n-1th pickup there are 3 possibilities and for n-2th 5 possibilities so here becomes a pattern though very hard to come up with 
        long long res=1;
        for(int i=1;i<=n;++i){
            //for n factorial
            res*=i;
            res%=1000000007;
            res*=(2*i-1);
            res%=1000000007;
        }
        return res%1000000007;
    }
};