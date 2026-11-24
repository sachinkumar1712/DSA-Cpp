#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse from left to right
        for (int i = 0; i < n; i++) {

            // Remove elements smaller than or equal to arr[i]
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // Previous greater element
            ans[i] = st.empty() ? -1 : st.top();

            // Push current element
            st.push(arr[i]);
        }

        return ans;
    }
};