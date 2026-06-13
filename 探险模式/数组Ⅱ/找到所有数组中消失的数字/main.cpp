#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        int temp;
        int lastTemp = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] == i + 1) {
                continue;
            }
            if (lastTemp == nums[i]) {
                continue;
            }
            lastTemp = nums[i];
            temp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[temp - 1] = lastTemp;
            i--;
        }
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] != i + 1) {
                v.push_back(i + 1);
            }
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
    vector<int> answer = solution.findDisappearedNumbers(nums);
    for (int i = 0; i < static_cast<int>(answer.size()); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}
