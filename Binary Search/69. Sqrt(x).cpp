class Solution {
    public:
        int mySqrt(int x) {
            long long low = 1, high = x;
    
            // Binary Search to find the square root
            while (low <= high) {
                long long mid = low + (high - low) / 2;
                long long square = mid * mid;
    
                if (square == x) return mid;  // If mid*mid equals x, return mid
                if (square > x) high = mid - 1;  // If mid*mid is greater than x, search in the left half
                else low = mid + 1;  // Otherwise, search in the right half
            }
    
            return high;  // When loop exits, high is the largest integer whose square ≤ x
    
            /*
            // Brute Force Approach (Commented)
            // Check every number from 1 to x to find the square root
    
            int ans = 0;
            for (long long i = 1; i * i <= x; i++) {  // Check all numbers until i*i <= x
                ans = i;
            }
            return ans;
    
            // Time Complexity: O(√x) - iterates from 1 to √x
            // Space Complexity: O(1) - uses only a few integer variables
            */
        }
    };
    