// fisher yate algorithm
// shuffling algorithm
// works by swapping
// https://youtu.be/4zx5bM2OcvA


class Solution {
public:
    vector<int> original;
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> temp = original;
        int n = temp.size();
        for(int i = n-1; i >= 0; --i) {
            int j = rand()%(i+1);
            swap(temp[i],temp[j]);
        }
        
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */