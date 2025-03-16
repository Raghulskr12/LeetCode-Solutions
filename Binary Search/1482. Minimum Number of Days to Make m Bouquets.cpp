class Solution {
    public:
        // Helper function to check if it's possible to make 'm' bouquets with 'k' adjacent flowers by 'maxDays' days.
        bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int maxDays) {
            int adjacentFlowers = 0, bouquetCount = 0;
            
            for (int i = 0; i < bloomDay.size(); i++) {
                // If the flower blooms within 'maxDays', count it.
                if (bloomDay[i] <= maxDays) {
                    adjacentFlowers++;
                } else {
                    // If we have enough adjacent flowers, make a bouquet.
                    bouquetCount += (adjacentFlowers / k);
                    adjacentFlowers = 0; // Reset count for the next batch.
                }
            }
            // Check for remaining adjacent flowers at the end of the array.
            bouquetCount += (adjacentFlowers / k);
    
            return bouquetCount >= m; // Return true if we can make 'm' bouquets.
        }
    
        int minDays(vector<int>& bloomDay, int m, int k) {
            int minDays = *min_element(bloomDay.begin(), bloomDay.end());
            int maxDays = *max_element(bloomDay.begin(), bloomDay.end());
    
            // If it's not possible to make 'm' bouquets, return -1.
            if ((long long)m * k > (long long)bloomDay.size()) return -1;
    
            // Binary search for the minimum number of days needed.
            while (minDays <= maxDays) {
                int midDays = (maxDays + minDays) / 2;
    
                if (canMakeBouquets(bloomDay, m, k, midDays)) {
                    maxDays = midDays - 1; // Try to minimize the days.
                } else {
                    minDays = midDays + 1; // Increase the day count.
                }
            }
            return minDays; // The minimum number of days required.
        }
    };
    