class SmallestInfiniteSet {
public:
    
    map<int,bool>  mp;
    //priority_queue<int, vector<int>, greater<int>> pq;
    SmallestInfiniteSet() {
        for(int i = 1; i < 1001; i++) {
            mp[i] = true;
        }
    }
    
    int popSmallest() {
        auto it = mp.begin();
        int n = it->first;
        mp.erase(it);
        return n;
    }
    
    void addBack(int num) {
        if(mp.find(num) == mp.end()) mp[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */