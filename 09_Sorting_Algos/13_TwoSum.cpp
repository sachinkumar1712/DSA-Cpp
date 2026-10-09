
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++) {
        int need = target - arr[i];

        if (mp.find(need) != mp.end()) {
            return {mp[need], i};
        }

        mp[arr[i]] = i;
    }

    return {};
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(arr, target);

    if (!ans.empty()) {
        cout << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}
