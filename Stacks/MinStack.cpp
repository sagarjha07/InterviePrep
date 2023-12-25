// LEETCODE 155

class MinStack {
public:
    stack<long long> s;
    long long mn;
    MinStack() {
        mn=INT_MAX;
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mn=val;
        } else if(val>=mn){
            s.push(val);
        } else {
            long long temp=2ll*val-mn;
            s.push(temp);
            mn=val;
        }
    }
    
    void pop() {
        if(!s.empty()){
            if(s.top()<mn){
                mn=2ll*mn-s.top();
            }
            s.pop();
        }
    }
    
    int top() {
        if(!s.empty()){
            if(s.top()<mn){
                return mn;
            }
        }
        return s.top();
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */