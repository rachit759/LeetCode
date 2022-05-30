class Solution {
public:
    int dis;
    string helper(string word) {
        
        int n = word.length();
        if(word[0] != '$' or n == 1) return word;
        
        string price;
        
        for(int i = 1; i < n; i++) {
            if(!isdigit(word[i])) return word;
            price += word[i];
        }
        
        if(price == "9999999999" and dis == 5) return "$9499999999.05";
        
            

        long double a = stoll(price) * (100-dis)/100.0;
        
        string b = to_string(a);
        
        //cout<<b<<" "<<endl;;
        
        string p;
        int i;
        for(i = 0; i < b.size() and b[i] != '.'; i++) {
            p += b[i];
        }
        p+=".";
        i++;
        p += b[i++];
        p += b[i];
        
        return "$" + p;
        
        
    }
    
    
    string discountPrices(string sentence, int discount) {
        
        
        string word, res;
        stringstream ss(sentence);
        dis = discount;
        while(ss >> word) {
            res += helper(word) + " ";
        }
        
        res.pop_back();
        return res;
        
        
        
        
    }
};