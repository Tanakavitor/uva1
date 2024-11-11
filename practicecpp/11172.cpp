#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (x > y) {
            cout << ">\n";
        } else if (x < y) {
            cout << "<\n";
        } else {
            cout << "=\n";
        }
    }
    return 0;
}