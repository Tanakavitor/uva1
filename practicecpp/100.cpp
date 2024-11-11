#include <iostream>
#include <algorithm>
using namespace std;

int function(int n) {
    int count = 1;
    long long num = n;  
    
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        count++;
    }
    return count;
}

int main() {
    int i, j;
    while (cin >> i >> j) {
        int maximo = 0;
        int start = min(i, j);
        int end = max(i, j);
        
        for (int n = start; n <= end; n++) {
            maximo = max(maximo, function(n));
        }
        
        cout << i << " " << j << " " << maximo << endl;
    }
    return 0;
}