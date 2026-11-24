#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove elements smaller than or equal to arr[i]
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // Next greater element
            ans[i] = st.empty() ? -1 : st.top();

            // Push current element
            st.push(arr[i]);
        }

        return ans;
    }
      // vector<int> nextLargerElement(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> ans(n,-1);
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(arr[j] > arr[i]){ // mil gaya arr[i] ka next greater
    //                 ans[i] = arr[j];
    //                 break;
    //             }
    //         }
    //     }
    //     return ans;
    // }
};