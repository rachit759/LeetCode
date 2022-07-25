class NumberContainers {
    unordered_map<int,set<int>>  mp;  // number, set of indices
    unordered_map<int,int>  imp;    // index number
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(imp.find(index) != imp.end()) {
            mp[imp[index]].erase(index);
            if(mp[imp[index]].empty()) mp.erase(imp[index]);
        }
        imp[index] = number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        
        if(mp.find(number) != mp.end()) {
            return *mp[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */