#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);
    
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    long long inv_count = 0;
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv_count += (n1 - i);
        }
    }
    
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
        
    return inv_count;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    long long inv_count = 0;
    if(left < right) {
        int mid = left + (right - left) / 2;
        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

int main() {
    int n;
    while(cin >> n && n!=0) {
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
            
        long long inversions = mergeSort(arr, 0, n-1);
        
        cout << (inversions % 2 ? "Marcelo" : "Carlos") << endl;
    }
    return 0;
}