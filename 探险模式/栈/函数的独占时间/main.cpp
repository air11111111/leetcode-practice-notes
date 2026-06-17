#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> v(n, 0);
        stack<int> s;
        int last = 0;

        for (int i = 0; i < static_cast<int>(logs.size()); i++) {
            int pos1 = logs[i].find(':');
            int pos2 = logs[i].find(':', pos1 + 1);

            int id = stoi(logs[i].substr(0, pos1));
            string type = logs[i].substr(pos1 + 1, pos2 - pos1 - 1);
            int time = stoi(logs[i].substr(pos2 + 1));

            if (type == "start") {
                if (!s.empty()) {
                    v[s.top()] += time - last;
                }
                s.push(id);
                last = time;
            } else {
                v[s.top()] += time - last + 1;
                s.pop();
                last = time + 1;
            }
        }
        return v;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> logs(m);
    for (string& log : logs) {
        cin >> log;
    }

    Solution solution;
    vector<int> answer = solution.exclusiveTime(n, logs);
    for (int i = 0; i < static_cast<int>(answer.size()); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}
