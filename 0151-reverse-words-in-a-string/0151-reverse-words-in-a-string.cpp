class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        vector<string> v;
        string word;
        while(ss>>word)
        {
            v.push_back(word);
        }
        reverse(v.begin(),v.end());
        string ans;
        for( auto i : v)
        {
            ans+=i+" ";
               
        }
        ans.erase(ans.length()-1,1);
        return ans;
    }
};