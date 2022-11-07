class Solution {
public:
    int maximum69Number (int num) {
        string t = to_string(num);
        for(char&c : t) {
            if(c == '6') {
                c = '9';
                return stoi(t);
            }
        }
        return num;
    }
};