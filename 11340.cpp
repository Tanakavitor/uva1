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

        long long totalCents = 0;

        while (m--) {
            string line;
            getline(cin, line);
            for (char &a : line) {
                totalCents += valor[(unsigned char)a];
            }
        }

        double totalDollars = totalCents / 100.0;
        cout << fixed << setprecision(2) << totalDollars << "$" << endl;
    }
    return 0;
}