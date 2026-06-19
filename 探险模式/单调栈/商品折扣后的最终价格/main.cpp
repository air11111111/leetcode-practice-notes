#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for (int i = 0; i < static_cast<int>(prices.size()); i++) {
            for (int j = i + 1; j < static_cast<int>(prices.size()); j++) {
                if (prices[i] >= prices[j]) {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int& price : prices) {
        cin >> price;
    }

    Solution solution;
    vector<int> answer = solution.finalPrices(prices);
    for (int i = 0; i < static_cast<int>(answer.size()); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}
