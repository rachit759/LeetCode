class LRUCache {
public:
    class node {
      public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    
    unordered_map<int, node*> m;
    int cap;
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void delnode(node* deletenode)
    {
        node* delnext = deletenode->next;
        node* delprev = deletenode->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
        
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node* resnode = m[key];
            int ans = resnode->val;
             m.erase(key);
            delnode(resnode);
            addnode(resnode);
            m[key] = head->next; 
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node* exist = m[key];
            m.erase(key);
            delnode(exist);
        }
        if(m.size()== cap)
        {
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }
        addnode(new node(key,value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */