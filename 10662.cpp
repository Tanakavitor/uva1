#include <iostream>
#include <limits.h>
using namespace std;

int t_to_r[20][20], r_to_h[20][20], h_to_t[20][20], travel[20], hotels[20], restaurants[20];
int main(){
    int t, r, h;
    while(cin >> t >> r >> h){
        for(int i = 0; i < t; i++){
            cin >> travel[i];
            for(int j = 0; j < r; j++){
                cin >> t_to_r[i][j];
            }
        }
        for(int j = 0; j < r; j++){
            cin >> restaurants[j];  
            for(int i = 0; i < h; i++){
                cin >> r_to_h[j][i];
            }
        }
        for(int j = 0; j < h; j++){
            cin >> hotels[j];  
            for(int i = 0; i < t; i++){
                cin >> h_to_t[j][i];
            }
        }
        
        int minr, minh, mint;
        int mp = INT_MAX;
        int at = 0;
        for(int i = 0; i < t; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < h; k++){
                    if(t_to_r[i][j] != 1 && r_to_h[j][k] != 1 && h_to_t[k][i] != 1){
                        at = travel[i] + restaurants[j] + hotels[k];
                        if(at < mp) {
                            mp = at;
                            mint = i;
                            minr = j;
                            minh = k;
                        }
                    }
                }
            }
        }
        if(mp == INT_MAX){
            cout << "Don't get married!" << endl;
        }
        else{
            cout << mint << " " << minr << " " << minh << ":" << mp << endl;
        }
    }
    return 0;
}