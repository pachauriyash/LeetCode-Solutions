class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //return -1;
        int mod=gas.size();
        int totalgas=0;
        int totalcost=0;
        int curr_gas=0;
        int index=0;
        for(int i=0;i<gas.size();i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0){
                index=i+1;
                curr_gas=0;
            }
        }
        if(totalgas<totalcost)return -1;
        return index;
        
    }
};