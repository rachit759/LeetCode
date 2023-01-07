class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        
        int n = gas.size();
        
        int total_gas(0), remaining_gas(0), start(0);
        
        for(int i = 0; i < n; i++) {
            
            int diff = gas[i]-cost[i];
            
            total_gas += diff; 
            
            remaining_gas += diff;
            
            if(remaining_gas < 0 ) {
                start = i+1;
                remaining_gas = 0;
            }
            
        }
        
        
        return total_gas >= 0 ? start : -1;
    
        
        
    }
};


// The algorithm is pretty easy to understand. Imagine we take a tour around this circle, the only condition that we can complete this trip is to have more fuel provided than costed in total. That's what the first loop does.

// If we do have more fuel provided than costed, that means we can always find a start point around this circle that we could complete the journey with an empty tank. Hence, we check from the beginning of the array, if we can gain more fuel at the current station, we will maintain the start point, else, which means we will burn out of oil before reaching to the next station, we will start over at the next station.

// ✔️ Question Conclusion
// There are N gas stations along a circular route, where the amount of gas at station i is arr[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
// At the beginning of the journey, the tank is empty at one of the gas stations.
// Return the minimum starting gas station’s index if you need to travel around the circuit once, otherwise return -1.
// ✔️ Solution - I (Best Approach)
// ##### Problem Note

// Completing the circuit means starting at i and ending up at i again.
// Both input arrays are non-empty and have the same length.
// Each element in the input arrays is a non-negative integer.
// Intuition :-
// As we know there consist a unique solution if exist.
// If we look at the problem, our point of concern should be the total amount of gas should be greater than the total cost. The only factor we need to consider is setting the starting point.