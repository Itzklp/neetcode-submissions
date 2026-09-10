class Solution {
   public:
    bool isnum(string s) {
        if (s[0] == '-' && s.size() > 1) return true;

        return isdigit(s[0]);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (isnum(token)) {
                st.push(stoi(token));
            } else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if (token == "+") {
                    st.push(a + b);
                } else if (token == "-") {
                    st.push(a - b);
                } else if (token == "*") {
                    st.push(a * b);
                } else {
                    st.push(a / b);
                }
            }
        }

        return st.top();
    }
};
