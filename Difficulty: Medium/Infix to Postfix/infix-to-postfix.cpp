class Solution {
  public:
    string infixToPostfix(string& s) {
        stack<char> st;
                string ans;

                for (char c : s) {
                    if (isalnum(c)) {
                        ans += c;
                    }
                    
                    else if (c == '(') {
                        st.push(c);
                    }
                    else if (c == ')') {
                        while (!st.empty() && st.top() != '(') {
                            ans += st.top();
                            st.pop();
                        }

                        st.pop();
                    }
                    
                    else {
                        while (!st.empty() && st.top() != '(' &&
                               (precedence(st.top()) > precedence(c) ||
                               (precedence(st.top()) == precedence(c) && c != '^'))) {

                            ans += st.top();
                            st.pop();
                        }

                        st.push(c);
                    }
                }

                while (!st.empty()) {
                    ans += st.top();
                    st.pop();
                }

                return ans;
    }
    
    //1st we have to set the precedence
    int precedence(char c) {
            if (c == '^')
                return 3;
            if (c == '*' || c == '/')
                return 2;
            if (c == '+' || c == '-')
                return 1;

            return 0;
        }
};
