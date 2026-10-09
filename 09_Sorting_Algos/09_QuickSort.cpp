
#include <iostream>
#include <vector>
using namespace std;
int partitionArray(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionArray(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main() {
    vector<int> arr = {8, 3, 1, 7, 0, 10, 2};

    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
