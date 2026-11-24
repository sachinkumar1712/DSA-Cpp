#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n, 0);
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Pop and count shorter or equal people
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
                ans[i]++;
            }

            // Count the first taller person
            if (!st.empty()) {
                ans[i]++;
            }

            // Push current person's height
            st.push(arr[i]);
        }

        return ans;
    }
};