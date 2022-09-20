class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
        for(int i = 1; i < size(w); i++) {  // prefix array
            w[i] += w[i-1];
        }
        v = w;
    }
    
    int pickIndex() {
        int index = rand()%v.back();                                //generating from 0 to v.back()-1
        return upper_bound(begin(v),end(v),index) - begin(v);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */