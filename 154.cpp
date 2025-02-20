#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <climits> 
using namespace std;

map<char, char> norm(const string& alocacao) {
    map<char, char> btw;
    stringstream ss(alocacao);
    string par;
    while (getline(ss, par, ',')) {
        btw[par[0]] = par[2]; 
    }
    return btw;
}

int main() {
    string linha;
    while (true) {
        vector<map<char, char>> cidades; 
        while (getline(cin, linha)) {
            if (linha == "#") break; 
            if (linha == "e") break; 
            cidades.push_back(norm(linha)); 
        }
        if (linha == "#") break; 
        int win = 0, mins = INT_MAX;
        for (size_t i = 0; i < cidades.size(); ++i) {
            int tt = 0;
            for (size_t j = 0; j < cidades.size(); ++j) {
                if (i == j) continue; 
                for (const auto& par : cidades[i]) {
                    if (cidades[j][par.first] != par.second) tt++;
                }
            }
            if (tt < mins) {
                mins = tt;
                win = i + 1; 
            }
        }
        cout << win << endl;
    }
    return 0;
}