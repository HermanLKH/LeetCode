class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = prices[0];
        int maxPrice;

        for (int price: prices) {
            // if yield better profit, update max price to sell
            if (price - minPrice > profit) {
                maxPrice = price;
                // calculate profit
                profit = maxPrice - minPrice;
            }
            // update current price for min price for next iteration only 
            // (last price wont be sell price)
            if (price < minPrice) {
                minPrice = price;
            }
        }
        return profit;
    }
};