#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < static_cast<int>(tokens.size()); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if (tokens[i] == "+") {
                    s.push(num1 + num2);
                } else if (tokens[i] == "-") {
                    s.push(num2 - num1);
                } else if (tokens[i] == "*") {
                    s.push(num1 * num2);
                } else {
                    s.push(int(num2 / num1));
                }
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> tokens(n);
    for (string& token : tokens) {
        cin >> token;
    }

    Solution solution;
    cout << solution.evalRPN(tokens) << '\n';
    return 0;
}
