class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        
        vector<int> ans;
        int sum = 0;
        for(auto ele : nums) {
            sum += ele&1 ? 0 : ele;
        }
        //cout<<sum;
        for(auto vec : q) {
            if(nums[vec[1]] & 1) {  // odd element
                if((nums[vec[1]] + vec[0]) % 2 == 0) {
                    nums[vec[1]] += vec[0];
                    sum += nums[vec[1]];
                }
                else nums[vec[1]] += vec[0];
            }
            else {
                if((nums[vec[1]] + vec[0]) % 2 == 0) {
                    nums[vec[1]] += vec[0];
                    sum += vec[0];
                }
                else {
                    sum -= nums[vec[1]];
                    nums[vec[1]] += vec[0];
                }
            }
            //for(auto ele : nums) cout<<ele<<" ";
            //cout<<endl;
            ans.push_back(sum);
        }
        
        return ans;
    }
};