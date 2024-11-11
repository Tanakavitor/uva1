#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int set[10000];

int findSet(int a) { 
    return (set[a] == a) ? a : (set[a] = findSet(set[a])); 
}

void unionSet(int a, int b) { 
    set[findSet(a)] = findSet(b); 
}

bool isConnected(int a, int b) { 
    return findSet(a) == findSet(b); 
}

int main() {
    int n_test;
    cin >> n_test;
    cin.ignore();

    while(n_test--) {
        int num_computers;
        cin >> num_computers;
        cin.ignore();

        for(int i = 0; i <= num_computers; ++i) {
            set[i] = i;
        }

        int successful = 0;
        int unsuccessful = 0;
        string line;

        while(getline(cin, line) && !line.empty()) {
            char command;
            int comp1, comp2;
            stringstream ss(line);
            ss >> command >> comp1 >> comp2;

            if(command == 'c') {
                unionSet(comp1, comp2);
            }
            else if(command == 'q') {
                if(isConnected(comp1, comp2)) {
                    successful++;
                } else {
                    unsuccessful++;
                }
            }
        }

        cout << successful << "," << unsuccessful << endl;
        if(n_test) cout << endl;
    }
    return 0;
}