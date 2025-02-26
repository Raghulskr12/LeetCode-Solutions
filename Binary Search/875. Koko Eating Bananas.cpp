class Solution {
    public:
        // Function to check if it's possible to eat all bananas within 'h' hours at a given eating speed
        bool canEatAll(vector<int>& piles, int speed, int h) {
            long long totalHours = 0;  // Stores total hours needed
            for (int bananas : piles) {
                totalHours += ceil((double)bananas / (double)speed);  // Time taken for full divisions
            }
            return totalHours <= h;  // Return true if it's possible within 'h' hours
        }
    
        int minEatingSpeed(vector<int>& piles, int h) {
            int maxBananas = *max_element(piles.begin(), piles.end());  // Maximum bananas in a single pile
            int low = 1, high = maxBananas;  // Search space for minimum speed
    
            while (low <= high) {
                int mid = (low + high) / 2;  // Mid represents the current eating speed
                if (canEatAll(piles, mid, h)) {
                    high = mid - 1;  // Try for a lower speed if possible
                } else {
                    low = mid + 1;  // Increase speed if not possible within 'h' hours
                }
            }
            return low;  // 'low' is the minimum speed needed to eat all bananas
        }
    };
    