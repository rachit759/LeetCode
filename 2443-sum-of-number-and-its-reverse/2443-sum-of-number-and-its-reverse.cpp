class Solution {
public:
    
    int rev(string n) {
        reverse(begin(n), end(n));
        return stoi(n);
    }
    
    
    
    bool sumOfNumberAndReverse(int num) {
        
        if(num == 0) return true;
        int n = num;
        for(int i = num/2; i <= num; i++) {
            //cout<<i<<" "<<rev(to_string(i))<<endl;
            if(i + rev(to_string(i))  == num) return true;         		
        }
        
        
        return false;
        
    }
};