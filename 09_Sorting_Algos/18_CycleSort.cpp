
#include <iostream>
#include <vector>
using namespace std;

void cycleSort(vector<int>& arr) {
    int n = arr.size();

    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
        int item = arr[cycleStart];
        int pos = cycleStart;
        // Find the correct position
        for (int i = cycleStart + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        if (pos == cycleStart) {
            continue;
        }
        // Skip duplicate elements
        while (pos < n && item == arr[pos]) {
            pos++;
        }
        if (pos == n) continue;

        // Place item in its correct position
        swap(item, arr[pos]);

        // Complete the cycle
        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }
            while (pos < n && item == arr[pos]) {
                pos++;
            }
            if (pos == n) break;
            swap(item, arr[pos]);
        }
    }
}

int main() {
    vector<int> arr = {5, 3, 1, 4, 2};\
    cycleSort(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
