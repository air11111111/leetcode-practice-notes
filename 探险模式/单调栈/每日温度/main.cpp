#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> v(n, 0);
        stack<int> s;

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && temperatures[i] >= temperatures[s.top()]) {
                s.pop();
            }

            if (!s.empty()) {
                v[i] = s.top() - i;
            } else {
                v[i] = 0;
            }
            s.push(i);
        }
        return v;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> temperatures(n);
    for (int& temperature : temperatures) {
        cin >> temperature;
    }

    Solution solution;
    vector<int> answer = solution.dailyTemperatures(temperatures);
    for (int i = 0; i < static_cast<int>(answer.size()); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}
