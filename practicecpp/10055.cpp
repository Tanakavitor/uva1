#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long unsigned h, e;
    while (cin >> h >> e) {
        cout << max(h, e) - min(h, e) << "\n";
    }
    return 0;
}