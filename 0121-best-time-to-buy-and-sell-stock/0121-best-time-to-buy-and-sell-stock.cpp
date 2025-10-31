class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = prices[0];

        for (int price: prices) {
            // calculate profit
            profit = max(price - minPrice, profit); 

            // update current price for min price for next iteration only 
            // (last price wont be sell price)
            minPrice = min(price, minPrice);
        }
        return profit;
    }
};