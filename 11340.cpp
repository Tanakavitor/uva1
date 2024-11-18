#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int k;
        cin >> k;

        vector<int> valor(256, 0);

        for (int i = 0; i < k; ++i) {
            char b;
            int c;
            cin >> b >> c;
            valor[(unsigned char)b] = c;
        }

        int m;
        cin >> m;
        cin.ignore();

        long long total_cents = 0;

        while (m--) {
            string line;
            getline(cin, line);
            for (char &a : line) {
                total_cents += valor[(unsigned char)a];
            }
        }

        double total_dollars = total_cents / 100.0;
        cout << fixed << setprecision(2) << total_dollars << "$" << endl;
    }
    return 0;
}