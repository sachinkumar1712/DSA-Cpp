
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> commonElements(vector<int>& a, vector<int>& b) {
    unordered_set<int> s(a.begin(), a.end());
    unordered_set<int> used;
    vector<int> ans;

    for (int x : b) {
        if (s.count(x) && !used.count(x)) {
            ans.push_back(x);
            used.insert(x);
        }
    }

    return ans;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {3, 4, 4, 5, 6};

    vector<int> ans = commonElements(a, b);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
