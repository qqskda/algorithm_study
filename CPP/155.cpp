class MinStack {
public:
    /** initialize your data structure here. */
    // Second will be used for tracking the min value
    stack<pair<int, int>> st;
    MinStack() {

    }

    void push(int x) {
        if (st.empty()) st.push({x,x});
        else {
            // Stack is not empty hence compare the value with current min
            if (st.top().second > x) st.push({x,x});
            else st.push({x, st.top().second});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
