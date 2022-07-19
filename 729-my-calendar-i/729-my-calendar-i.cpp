class MyCalendar {
public:
    vector<pair<int,int>> ans;
    MyCalendar() {
         
    }
    
    bool book(int s2, int e2) {
        for(auto [s1,e1] : ans) {
            if(s2 < e1 and e2 > s1) return false;
        }
        ans.push_back({s2,e2});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */