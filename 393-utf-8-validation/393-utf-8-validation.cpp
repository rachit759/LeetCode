// watch pepcoding video for better understanding
// https://www.youtube.com/watch?v=3zyxpFPKkEU&ab_channel=Pepcoding


class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int rbytes = 0;
        
        for(int val : data) {
            if(rbytes == 0) {
                if((val >> 7) == 0b0) rbytes = 0;
                else if((val >> 5) == 0b110) rbytes = 1;
                else if((val >> 4) == 0b1110) rbytes = 2;
                else if((val >> 3) == 0b11110) rbytes = 3;
                else return false;
            }
            else {
                if((val >> 6) == 0b10) --rbytes;
                else return false;
            }
        }
        
        if(rbytes == 0) return true;
        else return false;
    }
};



