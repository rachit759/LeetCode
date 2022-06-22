class Solution {
public:
    string maximumBinaryString(string nums) {
        
        string ans;
        int n(size(nums));
        int ones = count(begin(nums),end(nums),'1');
        int zero = count(begin(nums),end(nums),'0');
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == '0') break;
            count += 1;
        }
        
        
        if(zero > 1)
        return string(count + zero -1 ,'1') + string(1,'0') + string(ones-count,'1');
        
        return nums;
    }
};