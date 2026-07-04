class MyQueue {
private:
    stack<int> st;
    stack<int> q;

public:
    MyQueue() {
        
    }

    void push(int x) {
        if (st.empty() && q.empty()) {
            q.push(x);
        } else {
            while (!q.empty()) {
                int a = q.top();
                q.pop();
                st.push(a);
            }
            q.push(x);
            while (!st.empty()) {
                int a = st.top();
                st.pop();
                q.push(a);
            }
        }
    }

    int pop() {
        int a = q.top();
        q.pop();
        return a;
    }

    int peek() { return q.top(); }

    bool empty() { return q.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */