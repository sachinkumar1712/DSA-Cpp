#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n, -1);
        stack<int> st;

        // Find Previous Greater Element index
        for (int i = 0; i < n; i++) {

            // Pop smaller or equal elements
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // Store previous greater element index
            ans[i] = st.empty() ? -1 : st.top();

            // Push current index
            st.push(i);
        }

        // Convert PGE index into stock span
        for (int i = 0; i < n; i++) {
            ans[i] = i - ans[i];
        }

        return ans;
    }
};