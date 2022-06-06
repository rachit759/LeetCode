class TextEditor {
public:
    stack<char> front, back;
        
    TextEditor() {
        
    }
    
    string helper() {
        string res;
        int count = 10;
        while(front.size() and count--) {
            res = front.top() + res;
            front.pop();
        }
        
        for(auto ch : res) front.push(ch);
        
        return res;
        
    }
    
    void addText(string text) {
        for(auto ch : text) front.push(ch);
    }
    
    int deleteText(int k) {
        int count = 0;
        while(front.size() and k--) {
            front.pop();
            count += 1;
        }
        return count;
    }
    
    string cursorLeft(int k) {
        while(front.size() and k--) {
            back.push(front.top());
            front.pop();
        }
        return helper();
    }
    
    string cursorRight(int k) {
        while(back.size() and k--) {
            front.push(back.top());
            back.pop();
        }
        return helper();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */