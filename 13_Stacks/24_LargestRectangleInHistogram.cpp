#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        // next smaller element (index)
        stack<int> st;
        vector<int> nsi(n);
        for(int i=n-1;i>=0;i--){
            // pop mark push
            while(st.size() > 0 && arr[st.top()] >= arr[i]) 
                st.pop();
            if(st.size() > 0) nsi[i] = st.top();
            else nsi[i] = n; // -1 (no next smaller)
            st.push(i);
        }
        // previous smaller element (index)
        while(st.size() > 0) st.pop();
        vector<int> psi(n);
        for(int i=0;i<n;i++){
            // pop mark push
            while(st.size() > 0 && arr[st.top()] >= arr[i]) 
                st.pop();
            if(st.size() > 0) psi[i] = st.top();
            else psi[i] = -1; // -1 (no prev smaller)
            st.push(i);
        }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int height = arr[i];
            int width = nsi[i] - psi[i] - 1;
            int area = height * width;
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};