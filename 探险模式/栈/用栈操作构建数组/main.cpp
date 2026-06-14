#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int index = 0;
        for (int i = 1; i <= n; i++) {
            if (index >= static_cast<int>(target.size())) {
                break;
            }
            v.push_back("Push");
            if (target[index] == i) {
                index++;
            } else {
                v.push_back("Pop");
            }
        }
        return v;
    }
};

int main() {
    int size, n;
    cin >> size >> n;

    vector<int> target(size);
    for (int& value : target) {
        cin >> value;
    }

    Solution solution;
    vector<string> operations = solution.buildArray(target, n);
    for (const string& operation : operations) {
        cout << operation << '\n';
    }
    return 0;
}
