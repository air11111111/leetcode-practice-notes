#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int res = 0;
        for (int i = 0; i < static_cast<int>(heights.size()); i++) {
            while (s.top() != -1 && heights[i] <= heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int width = i - s.top() - 1;
                res = res > height * width ? res : height * width;
            }
            s.push(i);
        }

        while (s.top() != -1) {
            int height = heights[s.top()];
            s.pop();
            int width = static_cast<int>(heights.size()) - s.top() - 1;
            res = res > height * width ? res : height * width;
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int& height : heights) {
        cin >> height;
    }

    Solution solution;
    cout << solution.largestRectangleArea(heights) << '\n';
    return 0;
}
