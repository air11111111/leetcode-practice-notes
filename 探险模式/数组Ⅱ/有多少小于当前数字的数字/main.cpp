#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < static_cast<int>(v.size()); i++) {
            mp[v[i]].push_back(i);
        }
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            v[i] = mp[nums[i]][0];
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
    vector<int> answer = solution.smallerNumbersThanCurrent(nums);
    for (int i = 0; i < static_cast<int>(answer.size()); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}
