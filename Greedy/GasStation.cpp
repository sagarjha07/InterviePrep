// LEETCODE 134

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s=0;
        int tank=0;
        int total=0;
        for(int i=0;i<gas.size();i++){
            int consume=(gas[i]-cost[i]);
            tank+=consume;
            total+=consume;
            if(tank<0){
                tank=0;
                s=i+1;
            }
        }
        if(total>=0) return s;
        return -1;
    }
};