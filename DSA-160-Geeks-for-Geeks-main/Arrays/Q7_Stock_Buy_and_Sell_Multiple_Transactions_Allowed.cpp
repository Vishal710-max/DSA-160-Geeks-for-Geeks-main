#include <iostream>
#include <vector>
using namespace std;

/*
    ---------------- Stock Buy and Sell – Multiple Transactions Allowed ----------------

    You are given an array prices[] where prices[i] is the price of a stock on day i.

    You may perform multiple transactions:
      - Buy on any day
      - Sell on any later day
      - You may even buy and sell on the same day
      - You cannot hold more than 1 stock at a time

    Task:
      Find the MAXIMUM PROFIT possible.

    Key Idea:
      Whenever price goes UP from the previous day, we take the profit.

    Example:
      Input:  [100, 180, 260, 310, 40, 535, 695]
      Profit: (180 - 100) + (260 - 180) + (310 - 260) + (535 - 40) + (695 - 535)
            = 80 + 80 + 50 + 495 + 160
            = 865

      Input:  [4, 2, 2, 2, 4]
      Profit: (4 - 2) = 2

----------------------------------------------------------------------------------------
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
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
