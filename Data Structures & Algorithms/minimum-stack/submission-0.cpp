class MinStack {
   public:
    stack<int> st, min;
    MinStack() {}

    void push(int val) {
        st.push(val);

        if (min.empty() || val <= min.top()) {
            min.push(val);
        }
    }

    void pop() {
        int x = st.top();
        st.pop();

        if (min.top() == x) {
            min.pop();
        }
    }

    int top() { return st.top(); }

    int getMin() { return min.top(); }
};
