class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int>  mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int last = v.back(); // getting last value
        int index = mp[val];
        
        v[index] = last;   // updating vector of deleting with last value
        v.pop_back();  // removing from vector
        mp[last] = index;     // updating in the map
        mp.erase(val);   // removing from map
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */