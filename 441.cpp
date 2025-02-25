#include <iostream>

using namespace std;

int main(){
    int n;
    int cj[13];
    bool pend = false;
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        if (pend) {
            cout << endl;
        }
        pend = true;
        for(int i = 0; i < n; i++){
            cin >> cj[i];
        }
        for(int i = 0; i < n - 5; i++){
            for(int j = i + 1; j < n - 4; j++){
                for(int k = j + 1; k < n - 3; k++){
                    for(int l = k + 1; l < n - 2; l++){
                        for(int m = l + 1; m < n - 1; m++){
                            for(int ee = m + 1; ee < n; ee++){
                                cout << cj[i] << " " << cj[j] << " " << cj[k] << " " << cj[l] << " " << cj[m] << " " << cj[ee] << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}