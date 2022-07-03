class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        int len = 0;
        vector<int> diff(n-1);
        
        for(int i = 0; i < nums.size()-1; i++) {
            diff[i] = (nums[i+1]-nums[i]);
        }
        
        for(auto i : diff) cout<<i<<" ";
        
        int i = 0;
        int sz = diff.size();
        bool flag;
        while(i < sz and diff[i] == 0) i++;
        
        if(i < sz) {
            if(diff[i] > 0) flag = true;
            else flag = false;
            len++;
        }
        
        while(i < sz) {
            if(flag == true) {
                if(diff[i] < 0) {
                    flag = !flag;
                    ++len;
                }
            }
            else if(flag == false) {
                if(diff[i] > 0) {
                    flag = !flag;
                    ++len;
                }
            }
            i++;
        }
        
        
        
        
        
        
        
        return len+1;
        
    }
};