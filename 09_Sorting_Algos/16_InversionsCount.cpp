
#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int i = low, j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += mid - i + 1;
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= high) temp.push_back(arr[j++]);

    for (int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }

    return count;
}

long long mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return 0;

    int mid = low + (high - low) / 2;

    long long count = mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);

    return count;
}

int main() {
    vector<int> arr = {5, 3, 2, 4, 1};

    cout << mergeSort(arr, 0, arr.size() - 1) << endl;

    return 0;
}
