#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mn;

public:
    MinStack() {
        mn = LLONG_MAX;
    }

    void push(int value) {
        long long val = value;

        if (st.empty()) {
            st.push(val);
            mn = val;
        }
        else {
            if (val >= mn) {
                st.push(val);
            }
            else {
                // Encode the new minimum
                st.push(2 * val - mn);
                mn = val;
            }
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }

        if (st.top() < mn) {
            // Recover the previous minimum
            long long oldMin = 2 * mn - st.top();
            mn = oldMin;
        }

        st.pop();
    }

    int top() {
        if (st.top() < mn) {
            // Encoded value means actual top is current minimum
            return (int)mn;
        }

        return (int)st.top();
    }

    int getMin() {
        return (int)mn;
    }
};