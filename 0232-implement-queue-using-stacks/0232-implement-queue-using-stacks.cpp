// class MyQueue {
// public:
//     stack<int> s1,s2;
//     MyQueue() {
        
//     }       // time cpmplexity o(n);
    
//     void push(int x) {
//         while(s1.empty()==false)
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(x);
//         while(s2.empty()==false)
//         {
//             s1.push(s2.top());
//             s2.pop();
//         }
        
//     }
    
//     int pop() {
//         int ele = s1.top();
//         s1.pop();
//         return ele;
//     }
    
//     int peek() {
//         return s1.top();
//     }
    
//     bool empty() {
//         return s1.empty();
//     }
// };

class MyQueue {
public:
    stack<int> input,output;
    MyQueue() {
    }
    
    void push(int x) {   // amortised time complexity
        input.push(x);
    }
    
    int pop() {
        if(output.empty()==false)
        {
            int ele=output.top();
            output.pop();
            return ele;
        }
        else
        {
            while(input.empty()==false)
           {
            output.push(input.top());
            input.pop();
            }
            int ele=output.top();
            output.pop();
            return ele;
        }
    }
    
    int peek() {
           if(output.empty()==false)
        {
            return output.top();
        }
        else
        {
            while(input.empty()==false)
           {
            output.push(input.top());
            input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        return (input.empty()==true and output.empty()==true);
    }
};
