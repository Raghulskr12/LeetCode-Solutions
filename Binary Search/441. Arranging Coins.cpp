class Solution {
    public:
        int arrangeCoins(int n) {
            long long low = 1, high = n; // Use long long to prevent overflow
    
            while (low <= high) {
                long long mid = low + (high - low) / 2;
                long long totalCoins = (mid * (mid + 1)) / 2; // Sum of first 'mid' rows
    
                if (totalCoins > n) 
                    high = mid - 1; // Reduce the row count
                else 
                    low = mid + 1;  // Increase the row count
            }
    
            return high; // Last valid mid that fits within 'n' coins
        }
    };
    