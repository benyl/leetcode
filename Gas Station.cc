/*
Gas Station

http://oj.leetcode.com/problems/gas-station/

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

*/

// ============================================
// Version 1, brute force
// time complexity o(n^2), space complexity o(1)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.size() < 2) return 0;
        
        for(int i=0; i<gas.size(); ++i) { // go from current node to the whole station
            int balance = gas[i];
            bool canStart = true;
            for(int j=1; j<=gas.size(); ++j) {
                balance -= cost[(i+j) % gas.size()]; // travel to next station
                if(balance<0) { canStart=false; break; }
                balance += gas[(i+j) % gas.size()]; // refuel
            }
            if(canStart) return i;
        }
        
        return -1;
    }
};


// ============================================
// Version 2, dynamic programming with sliding window
// time complexity o(n), space complexity o(1)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.size() == 0) return -1;
        int pre = gas.size()-1, end = 0, balance = gas[end] - cost[end];
        while(pre != end) { // extand the path [pre+1, end] to full path
            if(balance < 0) { // if balance is not enough to go to next station
                balance += gas[pre] - cost[pre];
                pre = (pre + gas.size() - 1) % gas.size(); // extand to previous station
            } else {
                end = (end + 1) % gas.size(); // extand to next station
                balance += gas[end] - cost[end];
            }
        }
        
        return (balance < 0) ? -1 : (pre+1) % gas.size();
    }
};