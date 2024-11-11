#include <iostream>
using namespace std;

char dna1[201], dna2[201], dset[201];
bool isLetter(char a) { return a >= 'A' && a <= 'Z'; }
int findSet(int a) { return (a == dset[a]) ? a : findSet(dset[a]); }
bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }
void unionSet(int a, int b) { dset[findSet(a)] = findSet(b); }

int main() {
    int n, testCase = 0;
    while (cin >> n) {
        if (testCase > 0) {
            cout << endl;
        }
        testCase++;
        
        for (int i = 0; i < 201; i++) {
            dset[i] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> dna1[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> dna2[i];
        }
        
        bool validSolution = true;
        for (int i = 0; i < n; ++i) {
            if (isSameSet(dna1[i], dna2[i])) {
                continue;
            }
            else if (isLetter(findSet(dna1[i])) && !isLetter(findSet(dna2[i]))) {
                unionSet(dna2[i], dna1[i]);
            } 
            else if (isLetter(findSet(dna2[i])) && !isLetter(findSet(dna1[i]))) {
                unionSet(dna1[i], dna2[i]);
            }
            else if (!isLetter(findSet(dna1[i])) && !isLetter(findSet(dna2[i]))) {
                unionSet(dna1[i], dna2[i]);
            }
            else {
                validSolution = false;
                cout << "NO" << endl;
                break;
            }
        }

        if (validSolution) {
            cout << "YES" << endl;
            for (int i = '1'; i <= '9'; i++) {
                if (dset[i] != i && isLetter(findSet(dset[i]))) {
                    cout << (char)i << ' ' << (char)findSet(dset[i]) << endl;
                }
            }
        }
    }
    return 0;
}