#include <iostream>
#include <vector>
using namespace std;

/*
    ---------------- Stock Buy and Sell – Max One Transaction Allowed ----------------

    You are given an array prices[] where prices[i] is the stock price on day i.

    You are allowed ONLY ONE transaction:
        - 1 Buy
        - 1 Sell (after buying)

    Task:
        Find the MAXIMUM PROFIT possible.
        If no profit is possible, return 0.

    Logic:
        Track the MINIMUM price seen so far.
        At each day compute:
            profit = max(profit, prices[i] - min_price)

    Examples:

      Input: [7, 10, 1, 3, 6, 9, 2]
      Output: 8
      Explanation: Buy at 1 (day 2), sell at 9 (day 5)

      Input: [7, 6, 4, 3, 1]
      Output: 0
      Explanation: All decreasing → no profit

      Input: [1, 3, 6, 9, 11]
      Output: 10
      Explanation: Buy at 1, sell at 11

----------------------------------------------------------------------------------------
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);                    // Update minimum price
            maxProfit = max(maxProfit, price - minPrice);       // Check profit
        }

        return maxProfit;
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution obj;
    int ans = obj.maxProfit(prices);

    cout << "Maximum Profit: " << ans << endl;

    return 0;
}
