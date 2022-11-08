class Solution {
public:
    string makeGood(string &s) {
        
        int n = s.size();
        for(int i = 0; i < n-1; i++) {
            if(abs(s[i]-s[i+1]) == 32) {
                    s.erase(i,2);
                    makeGood(s);
            }
        }
        
        return s;
        
    }
};


// class Solution {
// public:
//     string makeGood(string &s) {
        
//         int n = s.size();
//         for(int i = 0; i < n-1; i++) {
//             if((islower(s[i]) and isupper(s[i+1])) or (islower(s[i+1]) and isupper(s[i]))) {
//                 if(tolower(s[i]) == tolower(s[i+1])) {
//                     s.erase(i,2);
//                     makeGood(s);
//                 }
//             }
//         }
        
//         return s;
        
//     }
// };