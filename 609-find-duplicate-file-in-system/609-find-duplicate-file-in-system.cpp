class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>>  mp;
        
        
        for(string s : paths) {
            
            int n = s.size(), i = 0;
            string path,file,text; 
            
            while(i < n and s[i] != ' ') path += s[i++];
            //path.pop_back();
            //cout<<path<<" ";
            i += 1;     
            while(i < n) {
                file = "", text = "";
                while(i < n and s[i] != '(') file += s[i++];
                i += 1;
                while(i < n and s[i] != ')') text += s[i++];
                i += 2;
                //cout<<file<<" "<<text<<endl;
                mp[text].push_back(path + "/" + file);
            }
        }
        
        for(auto i : mp) if(i.second.size() > 1) ans.push_back(i.second);
        
        
        
        
        return ans;
        
    }
};