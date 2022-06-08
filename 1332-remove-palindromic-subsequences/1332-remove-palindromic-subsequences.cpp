class Solution {
public:
    int removePalindromeSub(string s) {
        return 2 - (s == string(rbegin(s),rend(s)));
    }
};