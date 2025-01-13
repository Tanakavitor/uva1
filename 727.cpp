#include <iostream>
#include <stack>
#include <string>
using namespace std;

int ranking(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void solucao() {
    string line, result;
    stack<char> ops;
    
    while (getline(cin, line)) {
        if (line.empty()) break;
        char c = line[0];
        if (isdigit(c)) {
            result += c;
        }
        else if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                result += ops.top();
                ops.pop();
            }
            if (!ops.empty()) ops.pop();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!ops.empty() && ops.top() != '(' && 
                   ranking(ops.top()) >= ranking(c)) {
                result += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }
    
    while (!ops.empty()) {
        result += ops.top();
        ops.pop();
    }
    
    cout << result;  
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    
    while (n--) {
        solucao();
        if (n > 0) cout << endl << endl; 
        else cout << endl;  
    }
    return 0;
}