class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count=0;
        /*for(int i=0;i<people.size();i++){
            if(people[i]>limit){return count;}
            if(people[i]==limit){count++;}
            if(people[i]<limit){
                int temp=people[i];
                int rem=limit-temp;
                for(int j=i;j<people.size();j++){
                    if()
                }
                if(temp>limit){i--;}
                count++;
            }
        } */
        int i=0;
        int j=people.size()-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;j--;
            }
            else{
                j--;
            }
            count++;
        }
        return count;
    }
};