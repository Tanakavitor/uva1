#include <iostream>
#include <stack>
using namespace std;

bool sim(int n, int arr[]) {
    stack<int> station; 
    int tc = 1; 
    int cp = 0;  
    
    while (cp < n) {
        if (!station.empty() && station.top() == arr[cp]) {
            station.pop();
            cp++;
            continue;
        }
        
    
        while (tc <= n && (station.empty() || station.top() != arr[cp])) {
            station.push(tc);
            tc++;
        }
        
        if (!station.empty() && station.top() == arr[cp]) {
            station.pop();
            cp++;
        } else {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int arr[1000];
        while (true) {
            cin >> arr[0];
            if (arr[0] == 0) break;
            
            for (int i = 1; i < n; i++) {
                cin >> arr[i];
            }
            
            cout << (sim(n, arr) ? "Yes" : "No") << endl;
        }
        cout << endl; 
    return 0;
}
