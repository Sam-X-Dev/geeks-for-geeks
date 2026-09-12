class SpecialStack {
    stack<int> st;
    stack<int> maxSt;
  public:
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        // Push an element into the stack
        st.push(x);

        if (maxSt.empty()) {
            maxSt.push(x);
        }
        else {
            maxSt.push(max(x, maxSt.top()));
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if (st.empty())
            return;

            st.pop();
            maxSt.pop();
    }

    int peek() {
        // Returns the top element
        if (st.empty())
            return -1;

        return st.top();
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMax() {
        // Return maximum element of Stack
        if (maxSt.empty())
            return -1;

        return maxSt.top();
    }
};