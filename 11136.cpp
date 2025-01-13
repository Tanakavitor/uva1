#include <iostream>
#include <set>

using namespace std;

int main() {
    while (true) {
        int n_day;
        cin >> n_day;
        if (n_day == 0) return 0; 
        multiset<int> urna;
        unsigned long long int total = 0;

        for (int i = 0; i < n_day; i++) {
            int n_bill;
            cin >> n_bill;
            for (int j = 0; j < n_bill; j++) {
                int bill;
                cin >> bill;
                urna.insert(bill);
            }

            auto highest = --urna.end();  
            auto lowest = urna.begin();
            total += *highest - *lowest;

            urna.erase(lowest);  
            urna.erase(highest); 
        }
        cout << total << endl; 
    }
}