#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> arr(101, 0); 

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arr[num]++;
        }

        bool first = true;
        for (int i = 0; i < 101; i++) {
            while (arr[i] > 0) {
                if (!first) cout << ' ';
                cout << i;
                first = false;
                arr[i]--;
            }
        }
        cout << '\n'; 
    }
    return 0;
}