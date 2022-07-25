class NumberContainers {
    unordered_map<int,set<int>>  mp;  // number, set of indices
    unordered_map<int,int>  imp;    // index number
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(imp.find(index) != imp.end()) {
            mp[imp[index]].erase(index);
        }
        imp[index] = number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        
        if(mp.find(number) != mp.end()) {
            return mp[number].empty() ? -1 : *mp[number].begin();
        }
        return -1;
    }
};




// class NumberContainers {
// public:
//     unordered_map<int, int> ind_num;
//     unordered_map<int, set<int>> num_inds;
//     void change(int index, int number) {
//         auto it = ind_num.find(index);
//         if (it != end(ind_num))
//             num_inds[it->second].erase(index);
//         ind_num[index] = number;
//         num_inds[number].insert(index);
//     }
//     int find(int number) {
//         auto it = num_inds.find(number);
//         return it == end(num_inds) || it->second.empty() ? -1 : *begin(it->second);
//     }
// };

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */