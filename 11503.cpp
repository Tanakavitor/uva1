#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> size;

string findSet(const string &a) {
    if (parent[a] != a) {
        parent[a] = findSet(parent[a]);
    }
    return parent[a];
}

void unionSet(const string &a, const string &b) {
    string fathera = findSet(a);
    string fatherb = findSet(b);
    if (fathera != fatherb) {
        parent[fatherb] = fathera;
        size[fathera] += size[fatherb];
    }
}
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        parent.clear();
        size.clear();
        string aa, bb;
        for (int i = 0; i < n; i++) {
            cin >> aa >> bb;
            if (parent.find(aa) == parent.end()) {
                parent[aa] = aa;
                size[aa] = 1;
            }
            if (parent.find(bb) == parent.end()) {
                parent[bb] = bb;
                size[bb] = 1;
            }
            unionSet(aa, bb);
            cout << size[findSet(aa)] << endl;
        }
    }
    return 0;
}