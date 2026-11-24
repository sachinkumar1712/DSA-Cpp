#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse the circular array twice
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            // Remove smaller or equal elements
            while (!st.empty() && st.top() <= arr[idx]) {
                st.pop();
            }

            // Store answer only during the first traversal
            if (i < n) {
                ans[idx] = st.empty() ? -1 : st.top();
            }

            st.push(arr[idx]);
        }

        return ans;
    }
};