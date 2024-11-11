#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int>& arr) {
    int size = arr.size();
    int swapCount = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int size;
        cin >> size;
        vector<int> train(size);
        for (int i = 0; i < size; i++) {
            cin >> train[i];
        }
        int swaps = bubbleSort(train);
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
    }
    return 0;
}