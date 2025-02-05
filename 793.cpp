#include <iostream>
#include <string>
using namespace std;

int set[1000];

int arefriends(int a) { 
    return (set[a] == a) ? a : (set[a] = arefriends(set[a])); 
}

void unionSet(int a, int b) {
    set[arefriends(a)] = arefriends(b);
}

bool isSameSet(int a, int b) {
    return arefriends(a) == arefriends(b);
}

int main() {
    int tc;
    cin >> tc;
    cin.ignore();  
    cin.ignore();  

    for(int t = 0; t < tc; t++) {
        if(t > 0) cout << endl;
        
        int n;
        cin >> n;
        cin.ignore();  
        for(int i = 1; i <= n; i++) {
            set[i] = i;
        }

        string line;
        int successful = 0, unsuccessful = 0;

        while(getline(cin, line) && !line.empty()) {
            char command;
            int a, b;
            sscanf(line.c_str(), "%c %d %d", &command, &a, &b);

            if(command == 'c') {
                unionSet(a, b);
            } else if(command == 'q') {
                if(isSameSet(a, b)) {
                    successful++;
                } else {
                    unsuccessful++;
                }
            }
        }

        cout << successful << "," << unsuccessful << endl;
    }
    return 0;
}