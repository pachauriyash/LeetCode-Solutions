class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int ans=INT_MAX;
        long long sum=0;
        int tempsum=0;
        for(auto it:nums){
            sum+=it;
            if(sum>target)break;
        }
        if(target%sum==0)return nums.size()*target/sum;
        if(target>sum){
            tempsum=nums.size()*(target/sum);
            target=target-(target/sum)*sum;
        }
        int i=0,j=0;
        int summ=0;
        cout<<target<<" "<<tempsum;
        bool str=true;
        // do{
        //     summ+=nums[j];
        //     while(summ>target){
        //         summ-=nums[i];
        //         i++;
        //     }
        //     if(summ==target){
        //         if(j<i){
        //             int temp=j+1;
        //             temp+=nums.size()-i;
        //             ans=min(ans,temp);
        //         }else{
        //             ans=min(ans,j-i+1);
        //         }
        //     }
        //     if(j+1==nums.size())str=false;
        //     j=(j+1)%nums.size();

        // }while(((str && i<=j) || (!str && j<=i)) && i<nums.size());
        while(((str && i<=j) || (!str && j<i)) && i<nums.size()){
            summ+=nums[j];
            while(i<nums.size() && summ>target){
                summ-=nums[i];
                i++;
            }
            if(summ==target){
                if(j<i){
                    int temp=j+1;
                    temp+=nums.size()-i;
                    ans=min(ans,temp);
                }else{
                    ans=min(ans,j-i+1);
                }
                //break;
            }
            if(j+1==nums.size())str=false;
            j=(j+1)%nums.size();
        }
        return ans==INT_MAX?-1:ans+tempsum;
    }
};