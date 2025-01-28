//Problem Link: https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1
//GFG Profile Link: https://www.geeksforgeeks.org/user/nitinkumaf2c2/

class Solution{
public:
    string printMinNumberForPattern(string S){
        string result = "";
        stack<int> st;
        int num = 1;

        for (char ch : S) {
            if (ch == 'I') {
                st.push(num++);
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            } else if (ch == 'D') {
                st.push(num++);
            }
        }

        st.push(num++);

        while (!st.empty()) {
            result += to_string(st.top());
            st.pop();
        }

        return result;
    }
};