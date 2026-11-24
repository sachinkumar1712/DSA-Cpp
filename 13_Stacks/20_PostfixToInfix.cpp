#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string postToInfix(string& s) {
        stack<string> st;

        for (char ch : s) {
            if (ch == '+' || ch == '-' || ch == '*' ||
                ch == '/' || ch == '%' || ch == '^') {

                string b = st.top();
                st.pop();

                string a = st.top();
                st.pop();

                string expression = "(" + a + string(1, ch) + b + ")";

                st.push(expression);
            }
            else {
                st.push(string(1, ch));
            }
        }

        return st.top();
    }
};