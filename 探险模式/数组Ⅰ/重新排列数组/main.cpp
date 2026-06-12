#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            v.push_back(nums[i]);
            v.push_back(nums[i + n]);
        }
        return v;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(2 * n);
    for (int& num : nums) {
        cin >> num;
    }

    Solution solution;
    vector<int> answer = solution.shuffle(nums, n);
    for (int i = 0; i < static_cast<int>(answer.size()); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}
