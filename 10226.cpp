#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <iomanip>

int main(){
    int n;
    cin >> n;
    string bl;
    getline(cin, bl);
    while (n--)
    {
        map<string, int> frtr;
        int len = 0;
        getline(cin, bl);
        while (true)
        {
            string sp; 
            getline(cin, sp);
            if (sp.empty())break;
            frtr[sp]++;
            len++;
        }
        for (auto&valores : frtr){
                cout << valores.first << ' ' << fixed << setprecision(4)
           << (((double) valores.second) / len) * 100 << endl;

        }
        if (n) cout << endl;
    }
    return 0;


        
    }
    


