class CustomStack {
public:
    vector<int> v;
    int front;
    int n;
    CustomStack(int maxSize) {
        v = vector<int> (maxSize,0);
        n = maxSize; 
        front = -1;
    }
    
    void push(int x) {
        if(front < n-1) {
            front += 1;
            v[front] = x;   
        }
    }
    
    int pop() {
        if(front == -1) return -1;
        int temp = v[front];
        v[front] = 0;
        front -= 1;
        return temp;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i <= min(k-1,front); i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */