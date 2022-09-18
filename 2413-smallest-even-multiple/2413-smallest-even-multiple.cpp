class Solution {
public:
    int smallestEvenMultiple(int x) {
        return x%2 ==0 ? x : x*2;
    }
};