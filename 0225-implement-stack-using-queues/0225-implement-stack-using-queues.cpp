class MyStack {
    private:
    queue<int> q;
    queue<int> st;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(st.empty() && q.empty()){
            st.push(x);
        }else{
            q.push(x);
            while(!st.empty()){
                int a = st.front();
                st.pop();
                q.push(a);
            }
            while(!q.empty()){
                int a = q.front();
                q.pop();
                st.push(a);
            }
        }
    }
    
    int pop() {
        int a = st.front();
        st.pop();
        return a;
    }
    
    int top() {
        return st.front();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */