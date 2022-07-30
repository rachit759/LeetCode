class Solution {
public:
    
    vector<int> helper(string &temp) {
        vector<int> mp(26);
        for(char &c : temp) mp[c-'a']++;
        return mp;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> maxcount(26);
        vector<string> ans;
        int i;
        for(auto &word : words2) {
            auto vec = helper(word);
            for(i = 0; i < 26; i++) {
                maxcount[i] = max(maxcount[i],vec[i]);
            }
        }
        
        for(auto &word : words1) {
            auto vec = helper(word);
            for(i = 0; i < 26; i++) {
                if(maxcount[i] > vec[i]) break;
            }
            if(i == 26) ans.push_back(word);
        }
        
        return ans;
    }
};