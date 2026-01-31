    class Solution {
    public int maxProfit(int[] prices) {

        // Minimum price used as the buying price
        int minBuyPrice = prices[0];

        // Temporary profit for a single transaction
        int currentProfit = 0;

        // Total profit accumulated from multiple transactions
        int totalProfit = 0;

        // Start from day 1 since day 0 is the initial buy
        for (int i = 1; i < prices.length; i++) {

            // Profit if we sell on the current day
            currentProfit = prices[i] - minBuyPrice;

            // If selling today gives profit
            if (currentProfit > 0) {

                // Add this profit to total profit
                totalProfit += currentProfit;

                // Move buying price to next day (start a new transaction)
                if (i < prices.length - 1) {
                    minBuyPrice = prices[i + 1];
                }
            }

            // Update minimum buying price if a lower price is found
            minBuyPrice = Math.min(minBuyPrice, prices[i]);
        }

        // Return total profit
        return totalProfit;
    }
}


