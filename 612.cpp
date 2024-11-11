#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int countSwaps(const string& str) {
    int size = str.size();
    int swapCount = 0;
    string temp = str;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                swap(temp[j], temp[j + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

bool cmp(const string &a, const string &b){
    return countSwaps(a) < countSwaps(b);
}

int main(){
    int M;
    cin >> M;
    cin.ignore();
    while(M--){
        if (M < M - 1) cout << endl;
        int n, m;
        cin >> n >> m;
        cin.ignore();
        vector<string> arr(m);
        for(int i = 0; i < m; i++) {
            getline(cin, arr[i]);
        }
        stable_sort(arr.begin(), arr.end(), cmp);
        for(const auto &s : arr){
            cout << s << endl;
        }
        if (M > 0) cout << endl; 
    }
    return 0;
}