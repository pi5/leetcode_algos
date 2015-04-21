/*
 *    There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 *    You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 *    Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 *    Note:
 *    The solution is guaranteed to be unique.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

            int N = cost.size();
            int carFuel = 0;
            int stations = 0;
            for (int i = 0; i <= N*2; i++) {
                carFuel += gas[i%N];
                carFuel -= cost[i%N];
                if(carFuel < 0) {
                    carFuel = 0;
                    stations = -1;
                }

                if(stations == N) {
                    return i - N;
                }    
                stations++;
            }
            return -1;
        }
};


int main() {


} 
