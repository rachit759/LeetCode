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
        int last = v.back();
        v[mp[val]] = last;
        v.pop_back();
        mp[last] = mp[val];
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        //srand(1);
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