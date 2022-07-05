class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> hash;
        for(auto i : nums)
            hash.insert(i);
        
        int longstreak=0;
        
        for(auto ele : nums)
        {
            if(!hash.count(ele-1))
            {
                int curr = ele;
                int currstreak =1;
                while(hash.count(ele+1))
                {
                    ele +=1;
                    currstreak+=1;
                }
                longstreak= max(longstreak,currstreak);
            }
        }
        return longstreak;
    }
};