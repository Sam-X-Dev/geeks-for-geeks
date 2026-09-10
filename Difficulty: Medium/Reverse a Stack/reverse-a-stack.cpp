class Solution {
  public:
    void reverseStack(stack<int> &st) {
         stack<int> aux;
            while (!st.empty()) {
                aux.push(st.top());
                st.pop();
            }
            swap(st, aux);
    }
};