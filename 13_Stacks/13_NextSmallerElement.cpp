#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove elements greater than or equal to arr[i]
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // Next smaller element
            ans[i] = st.empty() ? -1 : st.top();

            // Push current element
            st.push(arr[i]);
        }

        return ans;
    }
};