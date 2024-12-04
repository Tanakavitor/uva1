    #include <iostream>
    #include <stack>
    #include <string>

    using namespace std;

    int main() {
        int n;
        cin >> n;
        cin.ignore(); 
        
        while (n--) {
            string line;
            getline(cin, line);
            stack<char> pp;
            bool valid = true;
            
            for(char c : line) {
                if(c == '(' || c == '{' || c == '[') {
                    pp.push(c);
                }
                else if(c == ')' || c == '}' || c == ']') {
                    if(pp.empty()) {
                        valid = false;
                        break;
                    }
                    
                    if((c == ')' && pp.top() == '(') ||
                    (c == '}' && pp.top() == '{') ||
                    (c == ']' && pp.top() == '[')) {
                        pp.pop();
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
            
            cout << (valid && pp.empty() ? "Yes" : "No") << '\n';
        }
        return 0;
    }