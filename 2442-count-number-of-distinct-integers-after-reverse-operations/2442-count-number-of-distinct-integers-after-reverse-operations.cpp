class Solution {
public:
    
    
    int rev(string n) {
        reverse(begin(n), end(n));
        return stoi(n);
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        
        unordered_set<int> s;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
		    s.insert(nums[i]);
            s.insert(rev(to_string(nums[i])));
        }
        
        return s.size();
        
    }
};