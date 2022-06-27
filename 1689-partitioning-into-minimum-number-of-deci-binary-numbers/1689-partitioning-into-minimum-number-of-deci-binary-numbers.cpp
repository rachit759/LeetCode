class Solution {
public:
    int minPartitions(string n) {
        vector<char> v(begin(n),end(n));
        return *max_element( begin(v), end(v)) - '0';
    }
};