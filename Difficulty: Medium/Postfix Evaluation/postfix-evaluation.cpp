class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;

        for (string sc : arr) {

            //Rem!! number --> push into the stack
            if (isdigit(sc[0]) || (sc.size() > 1 && sc[0] == '-')) {
                st.push(stoi(sc));
            }

            //Rem!! operator --> perform operation
            else {
                int val1 = st.top();
                st.pop();

                int val2 = st.top();
                st.pop();

                if (sc == "+")
                    st.push(val2 + val1);

                else if (sc == "-")
                    st.push(val2 - val1);

                else if (sc == "*")
                    st.push(val2 * val1);

                else if (sc == "/") {
                    if ((val2 < 0) != (val1 < 0) && val2 % val1 != 0)
                        st.push((val2 / val1) - 1);  // Floor Division
                    else
                        st.push(val2 / val1);
                }

                else if (sc == "^")
                    st.push((int)pow(val2, val1));
            }
        }

        return st.top();
    }
};