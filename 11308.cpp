#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

int main() {
    int tc; 
    cin >> tc;
    string null;
    getline(cin, null);
    
    while (tc--) {
        string foldername;
        getline(cin, foldername);
        
        transform(foldername.begin(), foldername.end(), foldername.begin(), ::toupper);
        
        int m, n, b;
        cin >> m >> n >> b;
        
        map<string, int> price;
        for (int i = 0; i < m; i++) {
            string inputname;
            int inputprice;
            cin >> inputname >> inputprice;
            price[inputname] = inputprice;
        }

        getline(cin, null);
        map<string, int> recipe;
        
        for (int i = 0; i < n; i++) {
            string recipename;
            getline(cin, recipename);
            int ingred; 
            cin >> ingred;
            int recipeprice = 0;
            
            for (int j = 0; j < ingred; j++) {
                string ingredname;
                int ingredamount;
                cin >> ingredname >> ingredamount;
                recipeprice += price[ingredname] * ingredamount;
            }
            
            if (recipeprice <= b) {
                recipe[recipename] = recipeprice;
            }
            getline(cin, null); 
        }
        
        vector<pair<string, int>> sortedRecipes(recipe.begin(), recipe.end());
        sort(sortedRecipes.begin(), sortedRecipes.end(), 
            [](const pair<string, int>& a, const pair<string, int>& b) {
                if (a.second == b.second) {
                    return a.first < b.first;
                }
                return a.second < b.second;
            });
            
        cout << foldername << endl;
        if (sortedRecipes.empty()) {
            cout << "Too expensive!" << endl;
        } else {
            for (const auto& [name, price] : sortedRecipes) {
                cout << name << endl;
            }
        }
        cout << endl; 
    }
    return 0;
}