#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <iomanip>

using namespace std;

bool dfr(int num1, int num2) {
    unordered_set<int> digits;
    for (int i = 0; i < 5; ++i) {
        digits.insert(num1 % 10);
        num1 /= 10;
        digits.insert(num2 % 10);
        num2 /= 10;
    }
    return digits.size() == 10;
}
void par(int N) {
    bool found = false;
    for (int fghij = 1234; fghij <= 98765 / N; ++fghij) {
        int abcde = fghij * N;
        if (abcde > 98765) continue;

        if (dfr(abcde, fghij)) {
            cout << setw(5) << setfill('0') << abcde << " / " 
                 << setw(5) << setfill('0') << fghij << " = " << N << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "There are no solutions for " << N << "." << endl;
    }
}
int main() {
    int N;
    bool firstCase = true;
    while (cin >> N && N != 0) {
        if (!firstCase) {
            cout << endl;
        }
        firstCase = false;
        par(N);
    }
    return 0;
}