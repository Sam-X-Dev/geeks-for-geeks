class Solution {
  public:
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        
        int x = st.top();
        st.pop();
        
        sortStack(st);
        sortInsert(st,x);
    }
    
    void sortInsert(stack<int> &st,int x){
        if(st.empty() || st.top() <= x){
            st.push(x);
            return;
        }
        
        int top = st.top();
        st.pop();
        
        sortInsert(st,x);
        st.push(top);
    }
};
