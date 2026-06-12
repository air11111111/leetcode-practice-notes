#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt++;
                if (cnt > count) {
                    count = cnt;
                }
            } else {
                cnt = 0;
            }
        }
        return count;
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
    cout << solution.findMaxConsecutiveOnes(nums) << '\n';
    return 0;
}
