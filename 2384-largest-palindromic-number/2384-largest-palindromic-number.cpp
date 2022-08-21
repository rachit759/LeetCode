class Solution {
public:
    string largestPalindromic(string num) {
        
        vector<int> vis(10,0);
        for(auto it : num) vis[it-'0']++; 

        string temp;
        int flag = -1;
        
        for(char i = '9'; i >= '0'; i--) {
            
            if(vis[i-'0'] & 1 and flag == -1) flag = i-'0';   // first greatest odd
            if(vis[i-'0'] >= 2 and i != '0') temp += string(vis[i-'0']/2,i);   // when even not zero
            if(temp.size() and i =='0') temp += string(vis[i-'0']/2,i); //  only zero when nothing is added
        }
        
     
        if(temp.empty() and flag == -1) return "0";   // when complete string is zero
       
        string front = temp;
        reverse(temp.begin(),temp.end());
        
        if(flag != -1) return front + to_string(flag) + temp;  // when we have any odd
        return front + temp;  
        
    }
};