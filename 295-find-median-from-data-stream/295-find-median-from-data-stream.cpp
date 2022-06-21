class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int l = maxheap.size();
        int r = minheap.size();
        
        if(l == 0) {
            maxheap.push(num);
        }
        else if(l == r) {
            if(num < minheap.top()) {
                maxheap.push(num);
            }
            else {
                int temp = minheap.top();
                minheap.pop();
                minheap.push(num);
                maxheap.push(temp);
            }
        }
        else {                               // means  l > r
            if(num >= maxheap.top())
                minheap.push(num);
            else {
                int temp = maxheap.top();
                maxheap.pop();
                minheap.push(temp);
                maxheap.push(num);
            }
            
        }
    }
    
    double findMedian() {
        int l = maxheap.size();
        int r = minheap.size();
        
        if(l > r) return (double)maxheap.top();
        else {
            return  ((double)maxheap.top()+(double)minheap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */