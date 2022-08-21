class Solution {
public:
    string largestPalindromic(string num) {
        
        vector<int> vis(10,0);
        int zero =0;
        for(auto it : num) vis[it-'0']++; 

    
        string temp;
        bool flag = 0;
        int pos;
        
        
        for(char i = '9'; i >= '0'; i--) {
            
            if(vis[i-'0']&1 and !flag) {
                flag = true;
                pos = i - '0';
            }
           
            if(vis[i-'0'] >= 2 and i != '0') {
                int c = vis[i-'0']/2;
                while(c--) temp += char(i);
            }
               if(temp.size() and i =='0') {
             int c = vis[0]/2;
                while(c--) temp += char('0');
        }
        
            
        }
        
     
        if(temp.empty() and !flag) return "0";
       
        string rev = temp;
        reverse(temp.begin(),temp.end());
        
        if(flag == true) 
        return rev + to_string(pos) + temp;
        return rev + temp;
        
    }
};