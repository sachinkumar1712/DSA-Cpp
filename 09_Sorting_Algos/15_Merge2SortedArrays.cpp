
#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            ans.push_back(a[i++]);
        } else {
            ans.push_back(b[j++]);
        }
    }

    while (i < a.size()) {
        ans.push_back(a[i++]);
    }

    while (j < b.size()) {
        ans.push_back(b[j++]);
    }

    return ans;
}

int main() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};

    vector<int> ans = mergeArrays(a, b);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
