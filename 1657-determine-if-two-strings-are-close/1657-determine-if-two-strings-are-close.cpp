class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size()) return false;
        unordered_map<char,int> m1,m2;
        set<char> c1,c2;
        multiset<int> f1,f2;
        
        for(int i =0; i < word1.size(); i++) {
            m1[word1[i]] += 1;
            m2[word2[i]] += 1;
        }
        
       for(auto i : m1) {
           c1.insert(i.first);
           f1.insert(i.second);
       }
        
        
       for(auto i : m2) {
           c2.insert(i.first);
           f2.insert(i.second);
       } 
        
       return c1 == c2 and f1 == f2; 
        
        
        
    }
};