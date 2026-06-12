#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(2 * n);
        for (int i = 0; i < n; i++) {
            v[i] = v[i + n] = nums[i];
        }
        return v;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }

    Solution solution;
    vector<int> answer = solution.getConcatenation(nums);
    for (int i = 0; i < static_cast<int>(answer.size()); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}
