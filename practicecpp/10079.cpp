#include <iostream>
using namespace std;

int main() {
    long long n;
    long long result;
    
    while (true) { 
        cin >> n;
        if (n < 0) {
            break;
        }
        result = (n * (n + 1)) / 2 + 1;
        cout << result << "\n";
    }
    
    return 0; 
}