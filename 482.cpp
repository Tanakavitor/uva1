#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    while (n--) {
        cin.ignore(); 
        string line;
        getline(cin, line);
        
        vector<int> indices;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            indices.push_back(num);
        }

        vector<string> values(indices.size());
        getline(cin, line);
        stringstream ss2(line);
        for (int i = 0; i < indices.size(); i++) {
            ss2 >> values[indices[i] - 1];
        }

        for (const string& value : values) {
            cout << value << endl;
        }

        if (n > 0) {
            cout << endl; 
        }
    }

    return 0;
}