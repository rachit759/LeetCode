class Solution {
public:
    
    vector<string> ans;
    int n;
    int j;
    string smallestNumber(string pattern) {
        
        n = pattern.length();
        j = 0;
        vector<int> nums(n+1), vis(n+2,0);        
        iota(begin(nums),end(nums),1);
        
        string vec;
        
        helper(nums,vis,vec,pattern);
         
        
        return ans.front();
       
        
       
        
    }
    
    void helper(vector<int> &nums, vector<int> &vis, string vec, string pat) {
        
        if(vec.size() == n + 1) {
            ans.push_back(vec);
            return;
        }
        
        for(int i = 0; i < size(nums); i++) {
            if(!vis[nums[i]]) { 
                
                if(vec.size() == 0) {
                    vec += to_string(nums[i]);
                vis[nums[i]] = 1;
                helper(nums,vis,vec,pat);
                vec.pop_back();
                vis[nums[i]] = 0;
                }
                
                else if((pat[j] == 'D' and nums[i] < vec.back()-'0')  or (pat[j] == 'I' and nums[i] > vec.back()-'0'))  {
                j++;    
                 vec += to_string(nums[i]);
                vis[nums[i]] = 1;
                helper(nums,vis,vec,pat);
                 vec.pop_back();
                vis[nums[i]] = 0;
                j--;
                }
            }
        }
        
    }
    
};