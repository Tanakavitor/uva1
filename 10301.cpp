#include <iostream>
#include <cmath>
using namespace std;

struct Circulo {
    double x, y;
    double raio;
};

int set[100];
int setSize[100];

int findSet(int a) {
    if (set[a] != a) {
        set[a] = findSet(set[a]);
    }
    return set[a];
}

void unionSet(int a, int b) {
    int rootA = findSet(a);
    int rootB = findSet(b);
    if (rootA != rootB) {
        set[rootA] = rootB;
        setSize[rootB] += setSize[rootA];
    }
}

bool intercept(Circulo &c1, Circulo &c2) {
    double dx = c1.x - c2.x;
    double dy = c1.y - c2.y;
    double distance = sqrt(dx * dx + dy * dy);
    return distance <= (c1.raio + c2.raio) && 
           distance > abs(c1.raio - c2.raio); // Check for non-point overlap
}

int main() {
    int tc;
    Circulo list[100];
    
    while (cin >> tc && tc != -1) {
        for (int i = 0; i < tc; i++) {
            set[i] = i;
            setSize[i] = 1;
        }

        for (int i = 0; i < tc; i++) {
            cin >> list[i].x >> list[i].y >> list[i].raio;
        }

        for (int i = 0; i < tc; i++) {
            for (int j = i + 1; j < tc; j++) {
                if (intercept(list[i], list[j])) {
                    unionSet(i, j);
                }
            }
        }

        int maxSize = 0;
        for (int i = 0; i < tc; i++) {
            if (set[i] == i) {
                maxSize = max(maxSize, setSize[i]);
            }
        }

        cout << "The largest component contains " << maxSize 
     << ((maxSize == 1) ? " ring." : " rings.") << endl;
    }
    return 0;
}