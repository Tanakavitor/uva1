#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int sets[30];

int findSet(int a) { 
    return (sets[a] == a) ? a : (sets[a] = findSet(sets[a])); 
}

void unionSet(int a, int b) { 
    sets[findSet(a)] = findSet(b); 
}

int main() {
    int n_test;
    cin >> n_test;
    cin.ignore();
    cin.ignore();

    for(int t = 0; t < n_test; ++t) {
        char maxNode;
        cin >> maxNode;
        cin.ignore();
        
        int nodeCount = maxNode - 'A' + 1;
        
        for(int i = 0; i < nodeCount; i++) {
            sets[i] = i;
        }

        string line;
        while(getline(cin, line) && !line.empty()) {
            int a = line[0] - 'A';
            int b = line[1] - 'A';
            unionSet(a, b);
        }

        vector<bool> seen(nodeCount, false);
        int max1 = 0;
        
        for(int i = 0; i < nodeCount; i++) {
            int root = findSet(i);
            if(!seen[root]) {
                seen[root] = true;
                max1++;
            }
        }

        cout << max1 << endl;
        if(t < n_test - 1) cout << endl;
    }
    return 0;
}