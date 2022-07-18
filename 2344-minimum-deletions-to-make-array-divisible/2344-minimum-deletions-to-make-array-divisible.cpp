// Explanation
// "divides all the elements of numsDivide"
// equals to
// "divides gcd of all the elements of numsDivide"
// where gcd is the greatest common divisor.

// So the first step, find out the gcd of numsDivide,
// then sort input nums A,
// and find out the smallest element A[i] in A divides gcd.

// We need to remove all elements smaller than A[i].
// If no such A[i], return -1


class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int g = numsDivide[0];
        for(auto i : numsDivide) 
            g = gcd(g,i);
        
        sort(begin(nums),end(nums));
        
        
        for(int i = 0; i < size(nums); i++) {
            if(g % nums[i] == 0) return i;
        }
        
        return -1;
        
    }
};