#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        int x, y, flag = 0;
        x = y = 1;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            mp[nums[i]] += 1;
        }
        for (int i = 1; i <= static_cast<int>(nums.size()); i++) {
            if (mp[i] == 2) {
                x = i;
            }
            if (mp[i] == 0) {
                flag = 1;
                y = i;
            }
        }
        if (flag == 0) {
            y = nums.size();
        }
        return {x, y};
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
    vector<int> answer = solution.findErrorNums(nums);
    cout << answer[0] << ' ' << answer[1] << '\n';
    return 0;
}
