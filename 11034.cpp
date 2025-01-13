#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    while(tc--) {
        queue<int> left, right;
        int l, m;
        cin >> l >> m;
        l *= 100; 
        
        for(int i = 0; i < m; i++) {
            int len;
            string side;
            cin >> len >> side;
            if(side == "left")
                left.push(len);
            else
                right.push(len);
        }
        
        int trips = 0;
        bool atLeft = true; 
        
        while(!left.empty() || !right.empty()) {
            int capacity = l;
            if(atLeft) {
                while(!left.empty() && left.front() <= capacity) {
                    capacity -= left.front();
                    left.pop();
                }
            } else {
                while(!right.empty() && right.front() <= capacity) {
                    capacity -= right.front();
                    right.pop();
                }
            }
            trips++;
            atLeft = !atLeft;
        }
        
        cout << trips << endl;
    }
    return 0;
}