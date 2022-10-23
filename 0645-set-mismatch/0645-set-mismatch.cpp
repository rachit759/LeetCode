class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i;
        for(i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                ans.push_back(nums[i]);
                break;
            }
        }
        nums.erase(nums.begin()+i);
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        sum = (n*(n+1))/2 - sum;
        ans.push_back(sum);
        return ans;
        
    }
};