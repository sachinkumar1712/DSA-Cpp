#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int operation(int& a, int& b, string& op) {
        if (op == "+") {
            return a + b;
        }
        else if (op == "-") {
            return a - b;
        }
        else if (op == "*") {
            return a * b;
        }
        else if (op == "^") {
            return pow(a, b);
        }
        else {  // Division
            return floor((float)a / b);
        }
    }

    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;

        for (string s : arr) {
            if (s == "+" || s == "-" || s == "*" ||
                s == "/" || s == "^") {

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                st.push(operation(a, b, s));
            }
            else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};