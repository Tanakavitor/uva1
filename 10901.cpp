#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Car {
    int arrival;
    int bank; 
};

void process_cars(int n, int t, int m) {
    vector<Car> cars(m);
    vector<int> result(m);
    queue<int> left, right;
    int curr_time = 0, pos = 0; 
    
    for(int i = 0; i < m; i++) {
        int time;
        string bank;
        cin >> time >> bank;
        cars[i] = {time, bank == "right"};
    }

    int car_index = 0;
    while(car_index < m || !left.empty() || !right.empty()) {
        while(car_index < m && cars[car_index].arrival <= curr_time) {
            if(cars[car_index].bank == 0) left.push(car_index);
            else right.push(car_index);
            car_index++;
        }

        queue<int>& current = pos == 0 ? left : right;
        queue<int>& other = pos == 0 ? right : left;

        if(current.empty() && other.empty() && car_index < m) {
            curr_time = cars[car_index].arrival;
            continue;
        }

        if(!current.empty()) {
            for(int i = 0; i < n && !current.empty(); i++) {
                result[current.front()] = curr_time + t;
                current.pop();
            }
        } else if(!other.empty()) {
            curr_time += t;
            pos = 1 - pos;
            continue;
        }

        curr_time += t;
        pos = 1 - pos;
    }

    for(int i = 0; i < m; i++) {
        cout << result[i] << endl;
    }
}

int main() {
    int c;
    cin >> c;
    for(int case_num = 0; case_num < c; case_num++) {
        int n, t, m;
        cin >> n >> t >> m;
        process_cars(n, t, m);

         if (case_num < c - 1) {
            cout << endl;
        }
    }

    return 0;
}
