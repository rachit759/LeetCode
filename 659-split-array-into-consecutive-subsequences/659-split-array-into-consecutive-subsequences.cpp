
// watch yt video for further explanation

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        if(size(nums) < 3) return false;
        
        unordered_map<int,int>  mp, hp;   // freq map // hypothetical map
        
        for(auto ele : nums) mp[ele]++; 
         
        for(auto ele : nums) {
            if(mp[ele] == 0) continue;
            
            if(hp[ele] > 0) {
                hp[ele]--;
                hp[ele+1]++;
                mp[ele]--;
            }
            else if(mp[ele] > 0 and mp[ele+1] > 0 and mp[ele+2] > 0) {
                mp[ele]--;
                mp[ele+1]--;
                mp[ele+2]--;
                hp[ele+3]++;
            }
            
            else return false;
            
                 
        }
        
        return true;
        
    }
};