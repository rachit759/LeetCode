class Solution {
public:
    
    static bool cmp(const int &a, const int &b) {
        
        string t1 = to_string(a) + to_string(b);
        string t2 = to_string(b) + to_string(a);;
        return stoll(t1) > stoll(t2);
        
        
    }
    
    
    string largestNumber(vector<int>& nums) {
        
        
        sort(begin(nums),end(nums),cmp);
        
        string ans;
        
        
        for(int i = 0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }
        
        return ans[0] == '0' ? "0" : ans;
        
    }
};