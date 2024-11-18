#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string st;
    while(1){
        cin >> st;
        if(st == "#"){break;}

        if(next_permutation(st.begin(),st.end())){
            cout << st <<endl;
        }
        else{
            cout << "No Successor" << endl;
        }

        
    }
}