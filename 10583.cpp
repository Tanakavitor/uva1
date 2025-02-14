#include <iostream>
using namespace std;

int parent[50001];
int rank[50001];

int findSet(int a) {
    if (parent[a] != a) {
        parent[a] = findSet(parent[a]); 
    }
    return parent[a];
}

void unionSet(int a, int b) {
    int fathera = findSet(a);
    int fatherb = findSet(b);
    if (fathera != fatherb) {
        parent[fathera] = fatherb;
    }
}

int main() {
    int n, m;
    int caseNumber = 1;

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            unionSet(a, b);
        }

        int distinctReligions = 0;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i) { 
                distinctReligions++;
            }
        }

        cout << "Case " << caseNumber << ": " << distinctReligions << endl;
        caseNumber++;
    }

    return 0;
}