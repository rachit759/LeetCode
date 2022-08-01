class cmp{
public:
    const int sums(int ele) const{
        int sum = 0;
        while(ele) {
            sum += ele%10;
            ele/=10;
        }
        return sum;
    }
    
   bool operator()(const int &a, const int &b) const {
        
       string t1 = to_string(a) + to_string(b);
       string t2 = to_string(b) + to_string(a);
       
       return stoll(t1) > stoll(t2);
       
    }
};




class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        
//         int n(size(nums));
//         int i;
//         for(i = 0; i < n; i++) {
//             if(nums[i] != 0) break;
//         }
        
        
//         if(i == n) return 0;
        
        map<int,multiset<int,cmp>>  mp;
        int flag = 1;
        for(int i = 0; i < size(nums); i++) {
            if(nums[i] != 0) flag = 0;
            string temp = to_string(nums[i]);
            mp[temp[0]-'0'].insert(nums[i]);
        }
        
        
        string ans;
    
        
        for(auto it = mp.rbegin(); it!=mp.rend(); it++) {
            
           if(it->first == 0) {
               
               if(flag == 1) ans+="0";
               else {
                    auto s = it->second;
                   ans += string(s.size(),'0');
               }
               
               continue;
           } 
            
           auto s = it->second;
            for(auto ele : s) {
                //cout<<ele<<" ";
                ans += to_string(ele);
            }
            
            
        }
        
        
        
        
        return ans;
        
        
        
        
        
    }
};