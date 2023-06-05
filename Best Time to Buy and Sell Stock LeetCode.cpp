#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) {
        return 0;
    }

    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            int currentProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, currentProfit);
        }
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int maxProfitValue = maxProfit(prices);

    cout << "Maximum Profit: " << maxProfitValue << endl;

    return 0;
}
